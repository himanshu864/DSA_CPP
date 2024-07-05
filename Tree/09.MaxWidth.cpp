#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

// f this question
// the part about indexing nodes is pretty smart
// other than that, sign int overflow, minus wtf is beyond me
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        long long ans = 1;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 1});
        while (q.size())
        {
            long long maxi = INT_MIN, mini = INT_MAX;
            long long wtf = q.front().second;
            int n = q.size();
            while (n--)
            {
                TreeNode *p = q.front().first;
                long long v = q.front().second;
                q.pop();

                mini = min(mini, v);
                maxi = max(maxi, v);

                if (p->left)
                    q.push({p->left, 2 * (v - wtf) + 1});
                if (p->right)
                    q.push({p->right, 2 * (v - wtf) + 2});
            }

            ans = max(ans, maxi - mini + 1);
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
    root->right->right->right = new TreeNode(8);

    cout << sol.widthOfBinaryTree(root) << endl;

    return 0;
}

// https://leetcode.com/problems/maximum-width-of-binary-tree/
