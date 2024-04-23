#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

class Solution
{
public:
    // Recursive Solution
    /*
        TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }

    */
    // Iterative Solution
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        TreeNode *tail = NULL, *temp = root;
        while (temp)
        {
            tail = temp;
            if (temp->val > val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (tail->val > val)
            tail->left = new TreeNode(val);
        else
            tail->right = new TreeNode(val);

        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(30);
    root->left = new TreeNode(20);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(25);
    root->right->left = new TreeNode(35);
    root->right->right = new TreeNode(50);

    inorder(root);
    cout << endl;

    int val = 45;
    sol.insertIntoBST(root, val);

    inorder(root);
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/insert-into-a-binary-search-tree/
