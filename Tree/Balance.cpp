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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int x = maxDepth(root->left), y = maxDepth(root->right);

        if (x < 0 || y < 0 || abs(x - y) > 1)
            return -1;
        return max(x, y) + 1;
    }

public:
    bool isBalanced(TreeNode *root) { return maxDepth(root) != -1; }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(10);

    cout << sol.isBalanced(root) << endl;
    return 0;
}

// https://leetcode.com/problems/balanced-binary-tree/
