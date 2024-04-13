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
    // brute as no use of complete
    int countNodes(TreeNode *root) // counting nodes
    {
        if (root == NULL)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return max(x, y) + 1;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(7);

    cout << "Depth (starting from 1 at root): " << sol.maxDepth(root) << endl;
    cout << "Total no. of Nodes: " << sol.countNodes(root) << endl;
    return 0;
}

/*
      8
   3     5
  4 9   7
*/

// https://leetcode.com/problems/count-complete-tree-nodes/
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
