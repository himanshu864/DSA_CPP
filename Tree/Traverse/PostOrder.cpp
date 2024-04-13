#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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
// Recursive
void helper(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    helper(root->left, ans);
    helper(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postrec(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        unordered_set<TreeNode *> visited;

        st.push(root);
        while (st.size())
        {
            TreeNode *p = st.top(); // V important as st.top() might change
            if (visited.count(p))
            {
                ans.push_back(p->val);
                visited.erase(p);
                st.pop();
            }
            else
            {
                visited.insert(p);
                if (p->right)
                    st.push(p->right);
                if (p->left)
                    st.push(p->left);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // Creating Binary Tree manually
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(2);

    // recursive
    vector<int> post = postrec(root);
    for (int i : post)
        cout << i << " ";
    cout << endl;

    // iterative
    vector<int> bari = sol.postorderTraversal(root);
    for (int i : bari)
        cout << i << " ";
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/binary-tree-postorder-traversal/
