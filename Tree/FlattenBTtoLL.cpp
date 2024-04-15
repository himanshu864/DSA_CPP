#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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

// Easy recursion by yours truly
class Solution3
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);
        if (root->left)
        {
            TreeNode *pre = root->left;
            while (pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
        }
        root->left = NULL;
    }
};

// Notice the traversal here is Right Left Root
// This is reversed preorder traversal
// instead of finding rightmost again and again, just store it externally
// and connect in return time.
// Notice little detail and ultra big brain super genius solution
class Solution2
{
    TreeNode *pre = NULL;

public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};

// O(N) - TC and O(1) - SC : Morris traversal solution
// Don't really understand it tbh
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *now = root;
        while (now)
        {
            if (now->left)
            {
                // Find current node's prenode that links to current node's right subtree
                TreeNode *pre = now->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = now->right;
                // Use current node's left subtree to replace its right subtree(original right
                // subtree is already linked by current node's prenode
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    sol.flatten(root);

    TreeNode *temp = root;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
