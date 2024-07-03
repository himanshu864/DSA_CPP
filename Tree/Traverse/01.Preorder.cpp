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
// Recursive Preorder
void helper(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->val);
    helper(root->left, ans);
    helper(root->right, ans);
}

vector<int> Preorder_rec(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

// My iterative Preorder
vector<int> Preorder_It(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);
    while (st.size())
    {
        TreeNode *p = st.top();
        st.pop();

        ans.push_back(p->val);
        if (p->right)
            st.push(p->right);
        if (p->left)
            st.push(p->left);
    }
    return ans;
}

// Bari iterative Pre
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;

    // stack will only contain parents
    TreeNode *t = root;

    while (st.size() || t)
    {
        if (t)
        {
            ans.push_back(t->val);
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top()->right;
            st.pop();
        }
    }
    return ans;
}

int main()
{
    // Creating Binary Tree manually
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(2);

    // Recursive Preorder traversal
    vector<int> pre = Preorder_rec(root);
    for (int i : pre)
        cout << i << " ";
    cout << endl;

    // Iterative Preorder Traversal
    vector<int> preIt = Preorder_It(root);
    for (int i : preIt)
        cout << i << " ";
    cout << endl;

    // Bari Iterative Preorder Traversal
    vector<int> prebit = preorderTraversal(root);
    for (int i : prebit)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/binary-tree-preorder-traversal/
