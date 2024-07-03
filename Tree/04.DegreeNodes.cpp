#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
public:
    int degree0(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        // for leaf nodes
        if (root->left == NULL && root->right == NULL)
            return 1;

        int x = degree0(root->left);
        int y = degree0(root->right);
        return x + y;
    }

    int degree2(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int x = degree2(root->left);
        int y = degree2(root->right);

        // very important to also carry previous 2's while returning
        if (root->left && root->right)
            return x + y + 1;
        return x + y;
    }

    int degree12(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int x = degree12(root->left);
        int y = degree12(root->right);

        if (root->left || root->right)
            return x + y + 1;
        return x + y;
    }

    int degree1(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int x = degree1(root->left);
        int y = degree1(root->right);

        // One child must be NULL
        // (l && !r) || (!l && r) = XOR
        if (!root->left ^ !root->right)
            return x + y + 1;
        return x + y;
    }

    int sumOfLeftLeaves(TreeNode *root, bool flag = false)
    {
        if (root == NULL)
            return 0;

        if (!root->left && !root->right && flag) // Leaf nodes && Left
            return root->val;

        // flag is true only when just coming from left
        int x = sumOfLeftLeaves(root->left, true);
        int y = sumOfLeftLeaves(root->right, false);
        return x + y;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(7);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(6);

    cout << "No. of degree Zero nodes (leaf): ";
    cout << sol.degree0(root) << endl;

    cout << "No. of degree Two nodes: ";
    cout << sol.degree2(root) << endl;

    cout << "No. of degree One or Two Nodes: ";
    cout << sol.degree12(root) << endl;

    cout << "No. of degree One Nodes: ";
    cout << sol.degree1(root) << endl;

    cout << "Sum of left leaves : ";
    cout << sol.sumOfLeftLeaves(root) << endl;
    return 0;
}

/*
     9
   2   4
  1   3
 5 7   6

*/

// https://leetcode.com/problems/sum-of-left-leaves/
