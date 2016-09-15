#include "sorting.h"
#include "stringstuff.h"
#include "matrices.h"
#include "linkedlists.h"
#include "graphs.h"

int sorts() {
    vector<int> vec = { 4, 5, 2, 6, 0, 7, 9, 1, 8, 10, 1 };
    vector<int> ret1 = mergeSort(vec, vec.size());
    vector<int> vec2 = { 4,3 ,1, 5, 6, 0, 7, 9, 1, 8};
    
    vector<int> ret2 = insertionSort(vec2);
    for (auto a : ret1)
    {
        cout << a << " ";
    }
    cout << endl;
    for (auto a : ret2)
    {
        cout << a << " ";
    }
    return 0;
}


int reverse_s() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    int i = 0;
    vector<int> temp;
    while (t != 0) {
        cin >> i;
        temp.push_back(i);
        t--;
    }
    for (auto a : temp)
    {
        printRecurse(a);
        cout << endl;
    }
    string s = "helloworld";
    string ss = recur(s);

    string test = "the sky is blue hello";
    vector<string> vec;
    string temp1;
    for (auto a : test)
    {
        if (a != ' ')
        {
            temp1 = temp1 + a;
        }
        else
        {
            vec.push_back(temp1);
            temp1 = "";
        }
    }

    vec.push_back(temp1);
    for (auto a : vec)
    {
        cout << a;
    }
    cout << endl;
    auto vret = reverseString(vec);
    for (auto a : vret)
    {
        cout << a;
    }
    return 0;
}





///* Driver program to test matrices functions */
int matrix()
{
    // Test Case 1
    int mat[N][N] =
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };


    // Tese Case 2
    /* int mat[N][N] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };
    */

    // Tese Case 3
    /*int mat[N][N] = {
    {1, 2},
    {4, 5}
    };*/

    displayMatrix(mat);

    cout << endl;
    rotateMatrix(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}

int LL_add()
{
    int sec[] = { 5, 5 };
    int first[] = { 9, 1, 4, 5 };
    Node* secLL = BuildNumber(sec, 2);
    Node* firstLL = BuildNumber(first, 4);
    int len1 = 0;
    Node* temp = firstLL;
    while (temp != nullptr)
    {
        len1++;
        temp = temp->next;
    }
    int len2 = 0;
    temp = secLL;
    while (temp != nullptr)
    {
        len2++;
        temp = temp->next;
    }

    // Padding the smaller number with 0s in front.

    //bool padSec= len1 > len2 ? true : false;
    //int padLen;
    //if (padSec)
    //{
    //    padLen = len1 - len2;
    //}

    //while (padLen != 0)
    //{
    //    Node* temp = new Node();
    //    temp->data = 0;
    //    temp->next = secLL;
    //    secLL = temp;
    //    padLen--;
    //}
    //Node* ss = secLL;
    //while (secLL != nullptr)
    //{
    //    cout << secLL->data << " ";
    //    secLL = secLL->next;
    //}
    int i = 0;
    Node* t = firstLL;
    while (t != nullptr)
    {
        cout << t->data << " ";
        t = t->next;
    }
    Node* r = addNumbers_withoutPadding0(firstLL, secLL);
    while (r != nullptr)
    {
        cout << r->data << " ";
        r = r->next;
    }

    while (firstLL != nullptr)
    {
        cout << firstLL->data << " ";
        firstLL = firstLL->next;
    }
    return 0;
}



graph* createAGraph()
{
    gnode* a = new gnode("A");
    gnode* b = new gnode("B");
    gnode* c = new gnode("C");
    gnode* d = new gnode("D");
    gnode* e = new gnode("E");
    gnode* f = new gnode("F");
    gnode* g = new gnode("G");
    gnode* h = new gnode("H");
    gnode* z = new gnode("Z");
    gnode* y = new gnode("Y");
    gnode* x = new gnode("X");

    
    a->m_children.push_back(d);
    a->m_children.push_back(e);
    a->m_children.push_back(b);
    b->m_children.push_back(e);
    b->m_children.push_back(c);
    c->m_children.push_back(f);
    e->m_children.push_back(f);

    graph* mygraph = new graph();
    mygraph->m_nodes.push_back(a);
    mygraph->m_nodes.push_back(b);
    mygraph->m_nodes.push_back(c);
    mygraph->m_nodes.push_back(d);
    mygraph->m_nodes.push_back(e);
    mygraph->m_nodes.push_back(f);
    mygraph->m_nodes.push_back(z);
    mygraph->m_nodes.push_back(y);
    mygraph->m_nodes.push_back(x);

    bool routeExist = RouteExists(mygraph, d, f);
    cout << "Route found ? " << routeExist << endl;
    gnode * found = DFSearch(mygraph, std::string("Y"));
    if (found != nullptr)
            cout << "found ... " << found->m_name << "..........";
    int arr[10] = { 0,4,6,7,9,65,89,90,98,100 };
    tnode* test = minimalBST(arr, 10);
    int height = findHeight(test);
    return mygraph;
}



int main(int argc, char* argv[])
{
    if (argc != 2) {
        return 0;
    }

    switch (argv[1][0]) {
    case 's':       sorts();      break;
    case 'l':       LL_add();      break;
    case 'm':       matrix();      break;
    case 'r':       reverse_s();    break;
    case 'g':       createAGraph(); break;// do something with graphs.
    default:
        break;
    }
  
}