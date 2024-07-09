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

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// my big-brain recursive solution
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 2. If doesn't exist
        if (!root)
            return NULL;

        // 1. Recursively search
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            // 3. If found
            // connect left-subtree to left of leftmost node of right-subtree
            TreeNode *leftest = root->right;

            // 4. If right doesn't exist, simply return left-subtree
            // also takes care edge case, if key node is leaf
            if (!leftest)
                return root->left;

            while (leftest->left)
                leftest = leftest->left;
            leftest->left = root->left;

            // 5. Return root of modified right-subtree
            // this replaces key node as child-subtree, thereby deleting it
            // notice due to recursive searching, we don't need to keep a parent
            // pointer and manually connect subtree to left/right as child
            return root->right;
        }
        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    inorder(root);
    cout << endl;

    int key = 3;
    int key = 7;
    root = sol.deleteNode(root, key);

    inorder(root);
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/delete-node-in-a-bst/
