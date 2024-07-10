#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// if a node has one on left, and one on right, that is clearly the Lowest Common Ancestor

class Solution
{
public:
    // Recursive
    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root->val > p->val && root->val > q->val)
            return LCA(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return LCA(root->right, p, q);
        return root;
    }

    // Iterative
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int a = p->val, b = q->val;
        if (a > b)
            swap(a, b);
        while (root)
        {
            int x = root->val;
            if (x == a || x == b || (x > a && x < b))
                return root;
            else if (x > a && x > b)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right->left = new TreeNode(7);

    TreeNode *p = root->left;
    TreeNode *q = root->left->right->left;
    cout << sol.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
