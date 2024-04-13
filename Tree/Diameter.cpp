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
    int helper(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int x = helper(root->left, ans);
        int y = helper(root->right, ans);
        ans = max(ans, x + y);
        return max(x, y) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        int idk = helper(root, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);
    root->left->left->left->left->left = new TreeNode(8);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(9);
    root->left->right->right->right = new TreeNode(10);
    root->left->right->right->right->right = new TreeNode(11);

    cout << sol.diameterOfBinaryTree(root) << endl;
    return 0;
}

// https://leetcode.com/problems/diameter-of-binary-tree/
