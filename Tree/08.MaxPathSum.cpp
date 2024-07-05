#include <iostream>
#include <vector>
#include <stack>
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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int helper(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;

        int x = max(0, helper(root->left, ans)); // VV IMP not to consider negative sum paths
        int y = max(0, helper(root->right, ans));

        ans = max(ans, root->val + x + y);

        return max(x, y) + root->val; // just find maximum sum path via height of node logic
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN; // important for possible negative ans
        helper(root, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(9);
    root->left = new TreeNode(-11);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(2);
    root->right->right->right = new TreeNode(2);
    root->right->right->right->left = new TreeNode(-5);
    cout << sol.maxPathSum(root) << endl;
    return 0;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
