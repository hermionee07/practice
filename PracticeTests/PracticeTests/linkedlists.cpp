#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "linkedlists.h"
using namespace std;


Node* BuildNumber(int* num, int len)
{
    // 1234
    // 1->nullptr
    Node* head = nullptr;
    Node* curr = head;
    int i = 0;
    while (i < len)
    {
        Node* temp = new Node();
        temp->data = num[i];
        temp->next = nullptr;
        if (i == 0)
        {
            head = temp;
            curr = temp;
        }
        else
        {
            curr->next = temp;
            curr = curr->next;
        }
        i++;
    }
    return head;
}

// add LL number creating a different LL for returning.
Node* addNumbers(Node* first, Node* sec, int& carry)
{
    if (first->next == nullptr && sec->next == nullptr)
    {
        carry = (first->data + sec->data) / 10;
        Node* ret = new Node();
        ret->data = (first->data + sec->data) % 10;
        ret->next = nullptr;
        return ret;
    }
    int retCarry = 0;
    Node* temp = addNumbers(first->next, sec->next, retCarry);
    Node* finalN = new Node();
    finalN->data = (first->data + sec->data + retCarry) % 10;
    finalN->next = temp;
    retCarry = (first->data + sec->data + retCarry) / 10;
    return finalN;
}

// add LL number creating a using one of the lists to store the result
Node* addNumbers_2(Node* first, Node* sec, int& carry)
{
    if (first->next == nullptr && sec->next == nullptr)
    {
        carry = (first->data + sec->data) / 10;
        //Node* ret = new Node();
        first->data = (first->data + sec->data) % 10;
        return first;
    }
    int retCarry = 0;
    Node* temp = addNumbers_2(first->next, sec->next, retCarry);
    first->data = (first->data + sec->data + retCarry) % 10;
    first->next = temp;
    retCarry = (first->data + sec->data + retCarry) / 10;
    return first;
}

Node* recurse(Node* first, Node* sec, int& carry)
{
    if (first->next == nullptr && sec->next == nullptr)
    {
        carry = (first->data + sec->data) / 10;
        //Node* ret = new Node();
        first->data = (first->data + sec->data) % 10;
        return first;
    }
    //int retCarry = 0;
    Node* temp = recurse(first->next, sec->next, carry);
    int a = (first->data + sec->data + carry) % 10;
    carry = (first->data + sec->data + carry) / 10;
    first->data = a;
    first->next = temp;

    return first;
}

void recurse_LL(Node* node, int& carry, int& len)
{
    if (len == 0)
    {

        int a = (node->data + carry) % 10;
        carry = (node->data + carry) / 10;
        node->data = a;
        return;
    }
    recurse_LL(node->next, carry, --len);
    int a = (node->data + carry) % 10;
    carry = (node->data + carry) / 10;
    node->data = a;
    return;
}
Node* addNumbers_withoutPadding0(Node* first, Node* sec)
{
    Node* temp = first;
    int len1 = 0;
    int len2 = 0;
    while (temp != nullptr)
    {
        len1++;
        temp = temp->next;
    }
    temp = sec;
    while (temp != nullptr)
    {
        len2++;
        temp = temp->next;
    }
    bool movSec = len1 < len2 ? true : false;
    int movLen = abs(len2 - len1);
    Node* firstTemp = first;
    Node* secTemp = sec;
    int carry = 0;
    temp = nullptr;
    Node* prev = nullptr;
    if (movSec) // sec is longer;
    {
        while (movLen != 0)
        {
            prev = secTemp;
            secTemp = secTemp->next;
            movLen--;
        }
        prev->next = recurse(first, secTemp, carry);
        return sec;

    }
    else   // first is longer
    {
        int len = movLen - 1;
        while (movLen != 0)
        {
            prev = firstTemp;
            firstTemp = firstTemp->next;
            movLen--;
        }
        prev->next = recurse(firstTemp, sec, carry);
        if (carry != 0)
        {
            recurse_LL(first, carry, len);
        }
        return first;
    }

}

// check if linked list is a palindrome
bool isPalindrome(Node* ll)
{
    if (ll == nullptr) // empty 
        return true;
    else if (ll->next == nullptr) // only 1 
        return true;
    Node* temp = ll;
    int len = 0;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    temp = ll;
    stack<int> myStack;
    int i = 1;
    while (i <= len / 2)
    {
        myStack.push(temp->data);
        ++i;
        temp = temp->next;
    }

    if (len%2 !=0) // this is odd
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        if (temp->data == myStack.top())
        {
            temp = temp->next;
            myStack.pop();
        }
        else
        {
            return false;
        }
    }
}


// check palindrom without using additional memory.
// can use stack memory.
void isPalindrome_2(Node* head)
{

}