#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void helper(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left) // to left, left, left, else right, then left, ..
    {
        ans.push_back(root->val);
        helper(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->val);
        helper(root->right, ans);
    }
}

void helper2(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (!root->left && !root->right) // if leaf
    {
        ans.push_back(root->val);
        return;
    }
    helper2(root->left, ans); // else
    helper2(root->right, ans);
}

void helper3(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->right) // go to right, else left
    {
        helper3(root->right, ans);
        ans.push_back(root->val); // push boundary in return time for reverse
    }
    else if (root->left)
    {
        helper3(root->left, ans);
        ans.push_back(root->val);
    }
}

vector<int> boundaryTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // dont push root if it's a leaf node, as helper2 takes care of it
    if (root->left || root->right)
        ans.push_back(root->val);

    // left boundary except leaf
    helper(root->left, ans);

    // all leafs
    helper2(root, ans);

    // right boundary in reverse. except root and leaf
    helper3(root->right, ans);
    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    root->left->right->left = new TreeNode<int>(8);
    root->left->right->right = new TreeNode<int>(9);

    vector<int> ans = boundaryTraversal(root);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
