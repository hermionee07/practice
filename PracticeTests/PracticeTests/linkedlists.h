#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;

};

Node* BuildNumber(int* num, int len);

// add LL number creating a different LL for returning.
Node* addNumbers(Node* first, Node* sec, int& carry);

// add LL number creating a using one of the lists to store the result
Node* addNumbers_2(Node* first, Node* sec, int& carry);

Node* recurse(Node* first, Node* sec, int& carry);

void recurse_LL(Node* node, int& carry, int& len);

Node* addNumbers_withoutPadding0(Node* first, Node* sec);

bool isPalindrome(Node* ll);