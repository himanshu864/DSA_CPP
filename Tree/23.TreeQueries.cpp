#include <iostream>
#include <vector>
#include <unordered_map>
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
    int n = 0;
    unordered_map<TreeNode *, int> height;

    int h(TreeNode *root)
    {
        if (!root)
            return -1;
        n++;
        return height[root] = 1 + max(h(root->left), h(root->right));
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        // 1. pre-compute height of each node
        h(root);
        // 2. pre-compute max-height of tree for each subtree removal
        vector<int> hq(n + 1);

        // bfs
        queue<TreeNode *> q;
        q.push(root);
        for (int depth = 0; q.size(); depth++)
        {
            // First, push heights of all cousins on the same level
            queue<TreeNode *> relevel;
            priority_queue<int> maxHeight;
            for (int x = q.size(); x; x--)
            {
                TreeNode *node = q.front();
                q.pop();

                relevel.push(node);
                maxHeight.push(height[node]);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Then max_height of tree after removing current node will be
            // depth + height_of_longest_cousin
            // depth - 1 if no cousin
            for (int x = relevel.size(); x; x--)
            {
                TreeNode *node = relevel.front();
                relevel.pop();
                if (maxHeight.top() != height[node])
                    hq[node->val] = depth + maxHeight.top();
                else
                {
                    maxHeight.pop();
                    hq[node->val] = depth + (maxHeight.size() ? maxHeight.top() : -1);
                    maxHeight.push(height[node]);
                }
            }
        }

        // 3. return answer
        vector<int> ans;
        for (int i : queries)
            ans.push_back(hq[i]);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    vector<int> queries = {4};
    vector<int> ans = sol.treeQueries(root, queries);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
