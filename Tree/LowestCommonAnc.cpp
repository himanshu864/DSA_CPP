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

// big brain recursion
// draw tree to understand
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *x = lowestCommonAncestor(root->left, p, q);
        TreeNode *y = lowestCommonAncestor(root->right, p, q);

        if (x == NULL)
            return y;
        else if (y == NULL)
            return x;
        else
            return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    cout << sol.lowestCommonAncestor(root, root->right->left, root->right->right->right)->val << endl;
    return 0;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
