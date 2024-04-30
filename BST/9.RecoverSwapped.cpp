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

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *pre = NULL;
        TreeNode *prefd = NULL;
        TreeNode *fd = NULL;

        stack<TreeNode *> st;
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        while (st.size())
        {
            // Try drawing graph for swapped inorder traversal

            // For non-adjecent swaps, there will be two dips
            // eg : 1 2 3 4 5 turned 1 5 3 4 2.
            // 5 to 3 and 4 to 2.
            // Need to swap 5 and 2

            // And for adjecent swaps, only one dip
            // eg 1 2 3 4 5 turned 1 2 4 3 5
            // 4 to 3
            // Need to swap 4 and 3

            // Hence keep a previous pointer and pre and curr in case of first dip
            // If encounter 2nd dip, simply swap previous of first dip and current node that must be smaller
            // And if no 2nd dip, swap previous of fd and fd

            TreeNode *curr = st.top();
            if (pre && pre->val > curr->val)
            {
                if (fd)
                {
                    swap(fd->val, curr->val);
                    return;
                }
                else
                {
                    prefd = pre;
                    fd = curr;
                }
            }
            st.pop();

            TreeNode *temp = curr->right;
            while (temp)
            {
                st.push(temp);
                temp = temp->left;
            }
            pre = curr;
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    sol.recoverTree(root);

    inorder(root);
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/recover-binary-search-tree/
