#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// pre-compute all parents
// also find start, cuz the question hates us
void helper2(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent, BinaryTreeNode<int> *&begin, int start)
{
    if (root->data == start)
        begin = root;

    if (root->left)
    {
        parent[root->left] = root;
        helper2(root->left, parent, begin, start);
    }
    if (root->right)
    {
        parent[root->right] = root;
        helper2(root->right, parent, begin, start);
    }
}

// check every node up, left and right child, recursively.
// while avoiding visited and updating ans to longest dist traveled
void helper(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent, unordered_set<BinaryTreeNode<int> *> &visited, int &ans, int dist)
{
    if (visited.count(root))
        return;

    ans = max(ans, dist);

    visited.insert(root);

    if (parent.count(root))
        helper(parent[root], parent, visited, ans, dist + 1);
    if (root->left)
        helper(root->left, parent, visited, ans, dist + 1);
    if (root->right)
        helper(root->right, parent, visited, ans, dist + 1);

    visited.erase(root);
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;
    BinaryTreeNode<int> *begin = NULL;
    helper2(root, parent, begin, start);

    unordered_set<BinaryTreeNode<int> *> visited;
    int ans = 0;
    helper(begin, parent, visited, ans, 0);
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->right->left = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(5);

    int start = 3;
    cout << timeToBurnTree(root, start) << endl;

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}

// https://www.naukri.com/code360/problems/time-to-burn-tree_1469067
