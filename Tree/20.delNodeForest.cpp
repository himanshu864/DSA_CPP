#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
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
    vector<TreeNode *> ans;

    // Use recursion to make forrests and correct connections
    TreeNode *helper(TreeNode *root, unordered_set<int> &del)
    {
        if (!root)
            return NULL;

        TreeNode *l = helper(root->left, del);
        TreeNode *r = helper(root->right, del);

        if (del.count(root->val))
        {
            if (l)
                ans.push_back(l);
            if (r)
                ans.push_back(r);
            return NULL;
        }

        root->left = l;
        root->right = r;
        return root;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> del;
        for (int d : to_delete)
            del.insert(d);

        // if root is to_delete
        TreeNode *rt = helper(root, del);
        if (rt)
            ans.push_back(rt);
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

    vector<int> to_delete = {3, 5};

    for (auto t : sol.delNodes(root, to_delete))
        cout << t->val << " ";
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/delete-nodes-and-return-forest
