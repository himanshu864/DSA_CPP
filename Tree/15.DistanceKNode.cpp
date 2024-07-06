#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

class Solution
{
    void helper(TreeNode *root, unordered_set<TreeNode *> &visited, unordered_map<TreeNode *, TreeNode *> &parent, vector<int> &ans, int k)
    {
        if (visited.count(root))
            return;

        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }

        visited.insert(root);

        if (root->left)
            helper(root->left, visited, parent, ans, k - 1);
        if (root->right)
            helper(root->right, visited, parent, ans, k - 1);
        if (parent.count(root))
            helper(parent[root], visited, parent, ans, k - 1);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // do a bfs traversal and store all parents, for upword
        unordered_map<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *p = q.front();
                q.pop();

                if (p->left)
                {
                    q.push(p->left);
                    parent[p->left] = p;
                }
                if (p->right)
                {
                    q.push(p->right);
                    parent[p->right] = p;
                }
            }
        }

        // start from target and move - left, right and up
        // keep track of path traveled and visted nodes
        vector<int> ans;
        unordered_set<TreeNode *> visited;
        helper(target, visited, parent, ans, k);
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
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    TreeNode *target = root->left;
    int k = 2;

    vector<int> ans = sol.distanceK(root, target, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
