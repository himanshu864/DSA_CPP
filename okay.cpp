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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        stack<TreeNode *> st;
        int i = 1;
        while (i < preorder.size())
        {
            if (preorder[i] < p->val)
            {
                p->left = new TreeNode(preorder[i++]);
                st.push(p);
                p = p->left;
            }
            else
            {
                if (st.size() && (preorder[i] > st.top()->val))
                {
                    p = st.top();
                    st.pop();
                }
                else
                {
                    p->right = new TreeNode(preorder[i++]);
                    p = p->right;
                }
            }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = sol.bstFromPreorder(preorder);

    inorder(root);
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
