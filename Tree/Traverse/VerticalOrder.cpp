#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> mp;      // verti, level, nodes
        queue<pair<TreeNode *, pair<int, int>>> q; // node, verti, level
        q.push({root, {0, 0}});

        while (q.size())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *p = q.front().first;
                int verti = q.front().second.first;
                int level = q.front().second.second;
                q.pop();

                mp[verti][level].insert(p->val);
                // mp[verti] = {level, p->val};

                if (p->left)
                    q.push({p->left, {verti - 1, level + 1}});
                if (p->right)
                    q.push({p->right, {verti + 1, level + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto x : mp)
        {
            vector<int> col;
            for (auto y : x.second)
                for (auto z : y.second)
                    col.push_back(z);
            ans.push_back(col);
        }
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

    vector<vector<int>> ans = sol.verticalTraversal(root);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
