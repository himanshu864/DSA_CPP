#include <iostream>
#include <cmath>
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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = 0, rh = 0;
        TreeNode *ltemp = root, *rtemp = root;

        while (ltemp)
            ltemp = ltemp->left, lh++;

        while (rtemp)
            rtemp = rtemp->right, rh++;

        if (lh == rh)
            return pow(2, lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);

    cout << sol.countNodes(root) << endl;
    return 0;
}

// https://leetcode.com/problems/count-complete-tree-nodes/
