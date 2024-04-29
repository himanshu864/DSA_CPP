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

// genius recursive solution
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root)
        {
            // brilliant recursion to search node while connecting parent
            if (key < root->val)
                root->left = deleteNode(root->left, key);
            else if (key > root->val)
                root->right = deleteNode(root->right, key);
            else
            {
                // if target node is leaf, direct delete
                if (!root->left && !root->right)
                    return NULL;

                // for one child, connect parent to that
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;

                // for second degree
                // find preceding inorder.. i.e rightmost node in left subtree
                TreeNode *temp = root->left;
                while (temp->right != NULL)
                    temp = temp->right;
                // modify target node to preceding node
                root->val = temp->val;
                // and similar delete on preceding node, by another genius searching and modifing recursion
                root->left = deleteNode(root->left, temp->val);
            }
        }
        return root;
    }
};

// my iterative inspired by striver
// can do better using functions and direct parent connect. but idk
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *p = NULL;
        // search node
        TreeNode *node = root;
        while (node && node->val != key)
        {
            p = node;
            if (node->val > key)
                node = node->left;
            else
                node = node->right;
        }

        // if root == NULL or node doesn't exist
        if (!node)
            return root;

        // if delete root
        if (!p)
        {
            // handle later, fuck you future me
            // fuck you too past me
            // haha lol you both are past me
            // wait
            if (!root->left && !root->right)
                return NULL;
            else if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                TreeNode *pre = root->left;
                while (pre->right)
                    pre = pre->right;
                pre->right = root->right;
                return root->left;
            }
        }

        // for leaf node, direct delete
        if (!node->left && !node->right)
        {
            if (p->val > node->val)
                p->left = NULL;
            else
                p->right = NULL;
        }
        // for single child, direct connect to parent
        else if (!node->left)
        {
            if (p->val > node->val)
                p->left = node->right;
            else
                p->right = node->right;
        }
        else if (!node->right)
        {
            if (p->val > node->val)
                p->left = node->left;
            else
                p->right = node->left;
        }
        // both childs, connect parent to left child
        // and conect right child to inorder predecessor
        else
        {
            TreeNode *store_right = node->right;
            if (p->val > node->val)
            {
                p->left = node->left;
                node = p->left;
            }
            else
            {
                p->right = node->left;
                node = p->right;
            }
            TreeNode *pre = node;
            while (pre->right)
                pre = pre->right;
            pre->right = store_right;
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
    root = sol.deleteNode(root, key);

    inorder(root);
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/delete-node-in-a-bst/
