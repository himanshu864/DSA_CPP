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
    // Recursive solution
    /*
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;

        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
    */

    // iterative solution
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (root->val == val)
                return root;
            else if (root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return NULL;
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

    int val = 25;
    cout << "is " << val << " present in bst? " << (sol.searchBST(root, val) ? "Yes" : "No") << endl;

    return 0;
}
