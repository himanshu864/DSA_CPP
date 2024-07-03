#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

void print(vector<int> &nums)
{
    for (int i : nums)
        cout << i << " ";
    cout << endl;
}

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
    ans.push_back(root->val);
    helper(root->right, ans);
}

vector<int> easyin(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

// My iterative, from postorder
vector<int> inorder(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    stack<TreeNode *> st;
    unordered_set<TreeNode *> visited;

    st.push(root);
    while (st.size())
    {
        TreeNode *p = st.top();
        if (visited.count(p))
        {
            ans.push_back(p->val);
            visited.erase(p);
            st.pop();
        }
        else
        {
            visited.insert(p);
            st.pop();

            if (p->right)
                st.push(p->right);
            st.push(p);
            if (p->left)
                st.push(p->left);
        }
    }
    return ans;
}

// Bari Iterative
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;

    TreeNode *t = root;
    while (st.size() || t)
    {
        if (t)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top()->right;
            ans.push_back(st.top()->val);
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

    // recursive
    vector<int> inrec = easyin(root);
    print(inrec);

    // my iterative
    vector<int> ans = inorder(root);
    print(ans);

    // iterative
    vector<int> bari = inorderTraversal(root);
    print(bari);

    return 0;
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/
