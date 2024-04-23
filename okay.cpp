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

// my iterative solution
class Solution2
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;

        // search for key while keeping parent
        TreeNode *p = NULL;
        TreeNode *temp = root;
        while (temp && temp->val != key)
        {
            p = temp;
            if (temp->val > key)
                temp = temp->left;
            else
                temp = temp->right;
        }

        // edge case root == key
        if (!p)
        {
            if (!temp->left && !temp->right)
                return NULL;
            else if (!temp->left && temp->right)
                return temp->right;
            else if (temp->left && !temp->right)
                return temp->left;
            else
            {
                p = temp;
                TreeNode *pre = temp->left;
                while (pre->right)
                {
                    p = pre;
                    pre = pre->right;
                }
                temp->val = pre->val;
                temp = pre;
            }
        }

        // if key doesn't exist, take care of
        // keep modifying until degree 0/1, then delete
        while (temp)
        {
            // leaf node, direct delete
            // VVVV.IMPORTANT : to connect to left when parent = delete node, as it indicates, left child was predecessor inorder.
            if (!temp->left && !temp->right)
            {
                (p->val >= temp->val) ? (p->left = NULL) : (p->right = NULL);
                temp = NULL;
            }
            // one degree
            else if (!temp->left && temp->right)
            {
                (p->val >= temp->val) ? (p->left = temp->right) : (p->right = temp->right);
                temp = NULL;
            }
            else if (temp->left && !temp->right)
            {
                (p->val >= temp->val) ? (p->left = temp->left) : (p->right = temp->left);
                temp = NULL;
            }
            // two degree
            else
            {
                // find preceding inorder while keeping parent
                p = temp;
                TreeNode *pre = temp->left;
                while (pre->right)
                {
                    p = pre;
                    pre = pre->right;
                }
                // modify node
                temp->val = pre->val;
                // delete pre node by using while loop
                temp = pre;
            }
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
