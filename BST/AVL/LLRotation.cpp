#include <iostream>
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

TreeNode *insertBST(TreeNode *root, int key)
{
    if (!root)
        return new TreeNode(key);

    if (root->val > key)
        root->left = insertBST(root->left, key);
    else if (root->val < key)
        root->right = insertBST(root->right, key);
    return root;
}

// Assuming LL-imbalance
TreeNode *LLrotation(TreeNode *root)
{
    TreeNode *newRoot = root->left;
    TreeNode *Br = newRoot->right;
    root->left = NULL;
    newRoot->right = root;
    root->left = Br;
    return newRoot;
}

int main()
{
    TreeNode *root = new TreeNode(30);
    root->left = new TreeNode(20);

    inorder(root);
    cout << endl;

    // Insert 10 - LL Imbalance
    int key = 10;
    root = insertBST(root, key);
    inorder(root);
    cout << endl;

    // LL - Rotation
    root = LLrotation(root);
    inorder(root);
    cout << endl;

    return 0;
}
