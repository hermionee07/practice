#include "graphs.h"
#include <utility>
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

    tnode* left = createMinimalBST(temp, i, mid - 1);
    tnode* right = createMinimalBST(temp, mid + 1, j);
    tnode* center = new tnode(*(temp + mid));
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

bool isBalanced(tnode * root, int & height)
{
    if (root == nullptr)
    {
        height = -1;
        return false;
    }
    if (root->m_left == nullptr && root->m_right == nullptr)
    {
        height = 0;
        return true;
    }
    int left;
    bool leftb = isBalanced(root->m_left, left);
    int right;
    bool rightb = isBalanced(root->m_right, right);

    height = left > right ? left + 1 : right + 1;

    if (abs(left - right) == 0 || abs(left - right) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createLL(vector<Node*> &vec, int data, int level)
{
    if (vec.size() >= level) // when there is already a node of that level
    {
        auto leadNode = vec[level];
        if (leadNode == nullptr)
        {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            vec[level] = newNode;
        }
        else
        {
            auto curr = leadNode;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            curr->next = newNode;
        }
        
    }
}

vector<Node*> createLLForEachDepth(tnode *root)
{
    queue<pair<tnode*, int>> myq;
    int height = findHeight(root);
    vector<Node*> myvec(height+1); // this should be the height of the tree.
    int level = 0;
    if (root != nullptr)
    {
        myq.push(std::pair<tnode*, int>(root, level));
    }
    
    while (!myq.empty())
    {
        auto data = myq.front().first;
        int currLevel = myq.front().second;
        createLL(myvec, data->m_value, currLevel);

        if (data->m_left != nullptr)
        {
            myq.push(std::pair<tnode*, int>(data->m_left, currLevel+1));
        }
        if (data->m_right != nullptr)
        {
            myq.push(std::pair<tnode*, int>(data->m_right, currLevel+1));
        }
        myq.pop();
            
    }
    return myvec;
}

// returns the root for which this node lies 
// on the left subtree
tnode* findRootOfSubtree(tnode* node)
{
    if (node->m_parent == nullptr || node == nullptr)
        return nullptr;
    if (node->m_parent->m_left == node)
        return node->m_parent;
    else
        return findRootOfSubtree(node->m_parent);
}

tnode * findInorderSuccessor(tnode * node)
{
    if (node == nullptr)
        return nullptr;
    if (node->m_left == nullptr && node->m_right == nullptr) // leaf node
    {
        if (node->m_parent->m_left == node)// left child of the parent
        {
            return node->m_parent;
        }
        else
        {
            return findRootOfSubtree(node);
        }
    }
    if (node->m_left == nullptr && node->m_right != nullptr)
        return node->m_right;
    if (node->m_left != nullptr && node->m_right != nullptr)
        return node->m_parent;
}

bool matchTree(tnode* big, tnode* small)
{
    if (big == nullptr && small == nullptr)
        return true;
    if (big->m_value != small->m_value) // if ever the values are not equal
        return false;                   // they arent equal.
    // if the values are equal then match the left and right subtrees too.
    matchTree(big->m_left, small->m_left) && matchTree(big->m_right, small->m_right);
}

bool isSubtree(tnode * bigRoot, tnode * smallRoot)
{
    if (bigRoot != nullptr && smallRoot != nullptr) // if good input
    {
        if (bigRoot->m_value == smallRoot->m_value) // values are equal
        {
            return matchTree(bigRoot, smallRoot);   // now match the subtrees
        }
        else // values arent equal, so search for the equal values first.
        {    // and then match.
            isSubtree(bigRoot->m_left, smallRoot) || isSubtree(bigRoot->m_right, smallRoot);
        }
    }
    else
    {
        return false;
    }
}

void findPaths(tnode * root, int value, vector<vector<tnode*>>& vec, int& sum )
{
    //if (root == nullptr) // bad root
    //    return;
    //if (sum == value)
    //{

    //    return;
    //}
    //findPaths(root->m_left, value, vec, sum + root->m_value);
    //findPaths(root->m_right, value, vec, sum + root->m_value);
    //
}

void pathFinder(tnode* root, int sum, vector<vector<tnode*>> &vec, vector<tnode*> &buffer, int sumTillNow)
{
    if (root == nullptr && sumTillNow != sum)
    {
        return;
    }
    if (root->m_left == nullptr && root->m_right == nullptr) // leaf node
    {
        if (sumTillNow != sum)
        {
            if (!buffer.empty())
            {
                auto a = buffer.back();
                sumTillNow = sumTillNow - a->m_value;
                buffer.pop_back();
            }
            return;
        }
        else
        {
            vec.push_back(buffer);
            buffer.clear();
            return;
        }
    }
    if (root == nullptr && sumTillNow == sum)
    {
        vec.push_back(buffer);
        buffer.clear();
        return;
    }
    if (root == nullptr && sumTillNow != sum)
    {
        //buffer.clear();
        if (!buffer.empty())
        {
            auto a = buffer.back();
            sumTillNow = sumTillNow - a->m_value;
            buffer.pop_back();
        }
        return;
    }
    else
    {
        buffer.push_back(root);
        sumTillNow = sumTillNow + root->m_value;
        if (sumTillNow == sum)
        {
            vec.push_back(buffer);
            buffer.clear();
            return;
        }
        else
        {
            pathFinder(root->m_left, sum, vec,  buffer, sumTillNow);
           
            pathFinder(root->m_right, sum, vec,  buffer, sumTillNow);
            
        }
    }
}
vector<vector<tnode*>> findPaths(tnode* root, int sum)
{
    vector<vector<tnode*>> vec;
    vector<tnode*> buffer;
    int sumTillNow = 0;
    pathFinder(root, sum, vec, buffer, sumTillNow);
    return vec;
}

// Basic DFS with a binary tree.
tnode* BasicDFS(tnode* root, int a)
{
    if (root == nullptr)
        return nullptr;
    root->m_visited = true;
    cout << root->m_value << " ";
    if (root->m_value == a)
    {
        return root;
    }
    auto t = BasicDFS(root->m_left, a);
    if (t != nullptr)
    {
        return t;
    }
    else
    {
        t = BasicDFS(root->m_right, a);
        if (t != nullptr)
            return t;
    }
}

void findNoOfPaths(tnode* qq)
{
    queue<tnode*> myq;
    myq.push(qq);
    while (!myq.empty())
    {
        auto a = myq.front();
        myq.pop();
        if (a != nullptr)
        {
            int sumtillnow = 0;
            int paths = 0;
            vector<tnode*> vec;
            findNumberOfPaths(a, 9, sumtillnow, paths, vec);
            myq.push(a->m_left);
            myq.push(a->m_right);
        }
    }
}

// find the number of paths which sum up to a number
// starts from a particular node.
void findNumberOfPaths(tnode* root, int sum, int &sumTillNow, int &paths, vector<tnode*>& vec)
{
    if (root == nullptr)
        return ;
    vec.push_back(root);
    sumTillNow += root->m_value;
    if (sum == sumTillNow)
    {
        for (auto a : vec)
            cout << a->m_value << "...";
        ++paths;
        cout << endl;
    }

    findNumberOfPaths(root->m_left, sum, sumTillNow, paths, vec);
    if (root->m_left != nullptr)
    {
        vec.pop_back();
        sumTillNow = sumTillNow - root->m_left->m_value;
    }
   findNumberOfPaths(root->m_right, sum, sumTillNow, paths, vec);
   if (root->m_right != nullptr)
   {
       vec.pop_back();
       sumTillNow = sumTillNow - root->m_right->m_value;
   }
    return;

}