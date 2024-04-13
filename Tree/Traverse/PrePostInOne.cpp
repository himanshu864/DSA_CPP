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

class Solution
{
public:
    vector<vector<int>> dfs(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> preorder, inorder, postorder;

        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (st.size())
        {
            pair<TreeNode *, int> x = st.top();
            st.pop();
            if (x.second == 1)
            {
                preorder.push_back(x.first->val);
                st.push({x.first, 2});
                if (x.first->left)
                    st.push({x.first->left, 1});
            }
            else if (x.second == 2)
            {
                inorder.push_back(x.first->val);
                st.push({x.first, 3});
                if (x.first->right)
                    st.push({x.first->right, 1});
            }
            else
                postorder.push_back(x.first->val);
        }

        ans.push_back(preorder);
        ans.push_back(inorder);
        ans.push_back(postorder);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = sol.dfs(root);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
