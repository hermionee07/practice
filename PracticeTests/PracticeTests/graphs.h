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
    tnode(int a) : m_value(a), m_left(nullptr), m_right(nullptr) {}
};

tnode* createMinimalBST(int* temp, int i, int j);

tnode* minimalBST(int* temp, int len);

int findHeight(tnode* root);