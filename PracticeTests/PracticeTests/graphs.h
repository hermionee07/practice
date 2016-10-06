#include "linkedlists.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// graph representation in adjacency lists.
// Can be both for directed an undirected graphs.
// for undirected graphs, the gnodes will have more
// children. 


class gnode
{
public:
    string m_name;
    vector<gnode*> m_children;
    bool m_visited;
    gnode(string a) : m_name(a), m_visited(false) {}

};

class graph
{
public:
    vector<gnode*> m_nodes;
};


gnode* BFSearch(graph * mygraph, string item);
gnode* DFSearch(graph * mygraph, string item);
bool RouteExists(graph* mygraph, gnode* a, gnode* b);

class tnode
{
public:
    int m_value;
    tnode* m_left;
    tnode* m_right;
    bool m_visited;
    tnode* m_parent;
    tnode(int a) : m_value(a), m_left(nullptr), m_right(nullptr), m_parent(nullptr) {}
};

tnode* createMinimalBST(int* temp, int i, int j);

tnode* minimalBST(int* temp, int len);

int findHeight(tnode* root);

// find if its a balanced binary tree.
// a balanced binary tree has the max difference
// of the lenght of the leaf node is not more than 1.

bool isBalanced(tnode * root, int & height);

// create a linked list for all every nodes in the same level
vector<Node*> createLLForEachDepth(tnode* root);

// Find inorder successor of a BST
tnode* findInorderSuccessor(tnode * node);

// Find if a large binary tree is a subtree of another large binary tree.
bool isSubtree(tnode* small, tnode* big);

// Find all the paths through a tree which sums up to a value.
// The path starts from the root, the path doesnt have to end at a leaf.
// Needs improvement - doesnt list all the paths possible.
// list the first path it finds.
void findPaths(tnode * root, int value, vector<vector<tnode*>>& vec, int &sum);

vector<vector<tnode*>> findPaths(tnode* root, int sum);

tnode* BasicDFS(tnode* root, int a);

void findNoOfPaths(tnode* qq);

void findNumberOfPaths(tnode* root, int sum, int& sumTillNow, int&paths, vector<tnode*>& vec);