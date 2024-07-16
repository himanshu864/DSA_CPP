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

void levelOrder(TreeNode *root)
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
// he's beter
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> getNode; // map value to it's node
        unordered_map<int, bool> isChild;       // to check if node has parent or not

        // Iteratively build parent+child and connect them
        for (auto &v : descriptions)
        {
            if (getNode.count(v[0]) == 0)
            {
                TreeNode *par = new TreeNode(v[0]);
                getNode[v[0]] = par;
            }
            if (getNode.count(v[1]) == 0)
            {
                TreeNode *child = new TreeNode(v[1]);
                getNode[v[1]] = child;
            }

            if (v[2] == 1)
                getNode[v[0]]->left = getNode[v[1]];
            else
                getNode[v[0]]->right = getNode[v[1]];

            isChild[v[1]] = true;
        }

        TreeNode *root = NULL;
        for (auto &v : descriptions)
        {
            if (isChild[v[0]] != true)
            {
                // if node has no parent then this is root node
                root = getNode[v[0]];
                break;
            }
        }
        return root;
    }
};

// My shit solution
class Solution2
{
    unordered_map<int, int> children;
    TreeNode *helper(int parent)
    {
        if (!children[parent])
            return NULL;

        TreeNode *node = new TreeNode(children[parent]);
        node->left = helper(node->val * -1);
        node->right = helper(node->val);
        return node;
    }

public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        // find root
        // he who is a parent but no ones child
        unordered_set<int> parents;
        for (auto v : descriptions)
            parents.insert(v[0]);

        for (auto v : descriptions)
            parents.erase(v[1]);

        TreeNode *root = NULL;
        for (auto s : parents)
            root = new TreeNode(s);

        // find parent to child hashmap
        // -ve parent for left child and +ve for right
        for (auto v : descriptions)
            children[v[0] * (v[2] == 1 ? -1 : 1)] = v[1];

        // recursive for the win
        root->left = helper(root->val * -1);
        root->right = helper(root->val);
        return root;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *root = sol.createBinaryTree(descriptions);
    levelOrder(root);
    return 0;
}

// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/
