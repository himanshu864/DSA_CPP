#include <iostream>
#include <vector>
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

// My genius
// Push at NULL after root, and push again everytime use encounter one in queue
// Works as checkpoint for each new level
// Just Remember to stop when queue is empty before pushing again to avoid infinite loop
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<int> level;
        while (q.size())
        {
            TreeNode *p = q.front();
            q.pop();
            if (p == NULL)
            {
                ans.push_back(level);
                level.clear();
                if (q.empty())
                    break;
                q.push(NULL);
            }
            else
            {
                level.push_back(p->val);
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
        }
        return ans;
    }
};

// Official
// For loop through queue until no new left and right children
class Solution2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            int n = q.size();
            vector<int> level;

            while (n--)
            {
                TreeNode *p = q.front();
                q.pop();
                level.push_back(p->val);

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

void levelorder(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        TreeNode *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}

int main()
{
    Solution sol;
    Solution2 sol2;

    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(2);

    cout << "Level Traversal easy: ";
    levelorder(root);
    cout << endl;
    cout << endl;

    cout << "My solution: ";
    vector<vector<int>> mine = sol.levelOrder(root);
    for (vector<int> i : mine)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Official Leetcode: ";
    vector<vector<int>> off = sol2.levelOrder(root);
    for (vector<int> i : off)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/
