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
    vector<int> topView(TreeNode *root)
    {
        map<int, int> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (q.size())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *p = q.front().first;
                int v = q.front().second;
                q.pop();

                if (!mp.count(v))
                    mp[v] = p->val;

                if (p->left)
                    q.push({p->left, v - 1});
                if (p->right)
                    q.push({p->right, v + 1});
            }
        }
        vector<int> ans;
        for (auto i : mp)
            ans.push_back(i.second);
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

    vector<int> ans = sol.topView(root);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
