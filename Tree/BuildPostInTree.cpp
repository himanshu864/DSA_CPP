#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

void levelOrder(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (q.size())
    {
        TreeNode *p = q.front();
        q.pop();
        if (p == NULL)
        {
            cout << endl;
            if (q.empty())
                break;
            q.push(NULL);
        }
        else
        {
            cout << p->val << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    cout << endl;
}

class Solution
{
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int is, int ie, int ps, int pe)
    {
        if (is > ie || ps > pe)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);

        int index = mp[root->val];

        root->left = helper(inorder, postorder, mp, is, index - 1, ps, ps + index - is - 1);
        root->right = helper(inorder, postorder, mp, index + 1, ie, ps + index - is, pe - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return helper(inorder, postorder, mp, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = sol.buildTree(inorder, postorder);

    cout << "Verify level by level:" << endl;
    levelOrder(root);

    return 0;
}

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
