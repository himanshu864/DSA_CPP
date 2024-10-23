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

void levelorder(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        int n = q.size();
        while (n--)
        {
            TreeNode *p = q.front();
            q.pop();
            cout << p->val << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        cout << endl;
    }
}

/*
1. Run BFS
2. While traversing take the sum of the child nodes & also keep storing the node in a buffer
3. After each stage of the BFS, traverse the buf & update the node with levelSum - (childrenSum)
*/

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        root->val = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size(), sum = 0;
            vector<TreeNode *> buf;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();
                buf.push_back(node);
                if (node->left)
                {
                    q.push(node->left);
                    sum += node->left->val;
                }
                if (node->right)
                {
                    q.push(node->right);
                    sum += node->right->val;
                }
            }
            for (auto node : buf)
            {
                int t = sum;
                if (node->left)
                    t -= node->left->val;
                if (node->right)
                    t -= node->right->val;
                if (node->left)
                    node->left->val = t;
                if (node->right)
                    node->right->val = t;
            }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    TreeNode *head = new TreeNode(5);
    head->left = new TreeNode(4);
    head->right = new TreeNode(9);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(10);
    head->right->right = new TreeNode(7);

    head = sol.replaceValueInTree(head);
    levelorder(head);
    return 0;
}

// https://leetcode.com/problems/cousins-in-binary-tree-ii/
