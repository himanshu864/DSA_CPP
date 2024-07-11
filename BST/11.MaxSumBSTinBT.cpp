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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// This is a great question since we want to check every subtree for BST
// and need to send boundaries from ground-up. Which is unique

class Solution
{
    vector<int> helper(TreeNode *root, int &ans)
    {
        // if NULL, important values, so that leaf node sum does change, and mini value in MAX, hence bst check
        if (!root)
            return {0, INT_MAX, INT_MIN};

        // Post-order recursion
        vector<int> l = helper(root->left, ans);
        vector<int> r = helper(root->right, ans);

        // For bst, root must be greater than greatest value on left and smaller than smallest value on right
        // If not bst, sum doesn't matter as we don't want ancestors to be bst, so max is MAXI.
        // &ans is already carrying max sum of left and right bst, if any
        if (l[2] >= root->val || r[1] <= root->val)
            return {-1, INT_MIN, INT_MAX};

        // If bst, we want to pass total sum of left, right and root. not individual or max
        int sum = l[0] + r[0] + root->val;
        // notice &ans is taking max sum, only if bst
        ans = max(ans, sum);
        return {sum, min(l[1], root->val), max(root->val, r[2])};
    }

    // {total sum, mini val, max val} so far, if bst
    // {0, INT_MIN, INT_MAX} if not bst, sum doesn't matter
public:
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    Solution sol;
    cout << sol.maxSumBST(root) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
