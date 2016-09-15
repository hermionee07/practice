#include "graphs.h"
#include <queue>

gnode* BFSearch(graph * mygraph, string item)
{
    queue<gnode*> myq;
    if (mygraph == nullptr || mygraph->m_nodes.empty())
        return nullptr;
    else
    {
        myq.push(mygraph->m_nodes[0]);
    }

    while (!myq.empty()) // this will find if the graph is a connected graph.
    {
        auto a = myq.front();
        a->m_visited = true;
        myq.pop();

        if (a->m_name.compare(item) == 0)
            return a;
        else
        {
            for (auto child : a->m_children)
            {
                myq.push(child);
            }
        }
    }

    for (auto node : mygraph->m_nodes) // will push the nodes which are not 
    {                             // connected to the graph
        if (!node->m_visited)
            myq.push(node);
    }

    while (!myq.empty())
    {
        auto a = myq.front();
        a->m_visited = true;
        myq.pop();

        if (a->m_name.compare(item) == 0)
            return a;
        else
        {
            for (auto child : a->m_children)
            {
                myq.push(child);
            }
        }
    }

    return nullptr;
}

gnode* DFSearch_n(gnode* node, string item)
{
    if (node == nullptr)
        return nullptr;
    node->m_visited = true;
    if (node->m_name.compare(item) == 0)
        return node;
    if (node->m_children.empty())
        return nullptr;
    for (auto child : node->m_children)
    {
        gnode * ret = DFSearch_n(child, item);
        if (ret && ret->m_name.compare(item) == 0)
            return ret;
    }
    return nullptr;
}

gnode* DFSearch(graph* mygraph, string item)
{
    if (mygraph == nullptr && mygraph->m_nodes.empty())
        return nullptr;
    auto node = mygraph->m_nodes[0];
    auto ret = DFSearch_n(node, item);
    if (ret != nullptr)
        return ret;
    queue<gnode*> to_DFS;
    for (auto a : mygraph->m_nodes)
    {
        if (!a->m_visited)
            to_DFS.push(a);
    }

    while (!to_DFS.empty())
    {
        auto a = to_DFS.front();
        to_DFS.pop();
        auto ret = DFSearch_n(a, item);
        if (ret != nullptr)
            return ret;
    }

    return nullptr;
}

// Directed graph, check if there is a route 
// between 2 nodes.
// Use level order search from one node and see if you can 
// get to the other node. 
// if you start from both the nodes?
bool RouteExists(graph* mygraph, gnode* a, gnode* b)
{
    if ((mygraph == nullptr) && (a == nullptr) && (b = nullptr))
        return false;
    queue<gnode*> myq;
    myq.push(a);
    while (!myq.empty())
    {
        auto item = myq.front();
        /*if (item->m_visited)
        {
            myq.pop();
            continue;
        }*/
        if (item->m_name == b->m_name)
            return true;
        myq.pop();
        auto children = item->m_children;
        for (auto child : children)
        {
            if (child->m_visited == true)
                continue;
            if (child->m_name == b->m_name)
                return true;
            else
            {
                child->m_visited = true;
                myq.push(child);
            }
        }
    }
    return false;
}

tnode* createMinimalBST(int* temp, int i, int j)
{
    if (i > j)
        return nullptr;

    int mid = (i + j) / 2;

    tnode* left = createMinimalBST(temp, i, mid-1);
    tnode* right = createMinimalBST(temp, mid+1, j);
    tnode* center = new tnode(*(temp+mid));
    center->m_left = left;
    center->m_right = right;

    return center;
}

tnode* minimalBST(int* temp, int len)
{
    return createMinimalBST(temp, 0, len - 1);
}

int findHeight(tnode* root)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->m_left == nullptr && root->m_right == nullptr)
    {
        return 0;
    }


    int a = findHeight(root->m_left);
    int b = findHeight(root->m_right);
    return a > b ? a + 1 : b + 1;

}