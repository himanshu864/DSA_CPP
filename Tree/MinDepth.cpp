#include <iostream>
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

// DFS
class Solution2
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int x = minDepth(root->left);
        int y = minDepth(root->right);

        if (x == 0 && y == 0)
            return 1;
        else if (x == 0)
            return y + 1;
        else if (y == 0)
            return x + 1;

        return min(x, y) + 1;
    }
};

// Better BFS here
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (q.size())
        {
            i++;
            int n = q.size();
            while (n--)
            {
                TreeNode *p = q.front();
                if (!p->left && !p->right)
                    return i;

                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(10);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(8);

    cout << "Min Depth: " << sol.minDepth(root) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-depth-of-binary-tree/
