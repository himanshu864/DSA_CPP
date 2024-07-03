#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    bool helper(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        if (!l || !r || l->val != r->val)
            return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }

public:
    bool isSymmetric(TreeNode *root) { return helper(root->left, root->right); }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << sol.isSymmetric(root) << endl;
    return 0;
}

// https://leetcode.com/problems/symmetric-tree/
