#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// This is a great question since we want to check every subtree for BST
// and need to send boundaries from ground-up. Which is unique

// {size, Mini value, maxi val}
// Left child max must be smaller than root val
// right child mini must be greater than root val
vector<int> helper(TreeNode *root)
{
    if (!root)
        return {0, INT_MAX, INT_MIN};

    vector<int> l = helper(root->left);
    vector<int> r = helper(root->right);

    if (l[2] >= root->data || r[1] <= root->data)
        return {max(l[0], r[0]), INT_MIN, INT_MAX};

    return {l[0] + r[0] + 1, min(l[1], root->data), max(root->data, r[2])};
}

int largestBST(TreeNode *root)
{
    return helper(root)[0];
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);

    cout << largestBST(root) << endl;
    return 0;
}
