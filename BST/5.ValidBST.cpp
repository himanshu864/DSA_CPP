#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(double x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    bool helper(TreeNode *root, long mini, long maxi)
    {
        if (!root)
            return true;
        int x = root->val;
        if (x <= mini || x >= maxi)
            return false;
        return helper(root->left, mini, x) && helper(root->right, x, maxi);
    }

public:
    bool isValidBST(TreeNode *root) { return helper(root, LONG_MIN, LONG_MAX); }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << "is binary tree BST? " << (sol.isValidBST(root) ? "Yes" : "No") << endl;
    return 0;
}

// https://leetcode.com/problems/validate-binary-search-tree/
