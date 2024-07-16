#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
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
    string s = "";
    string t = "";
    vector<char> output;

    void DFS(TreeNode *&node, int &sv, int &tv)
    {
        if (node->val == sv)
            for (auto c : output)
                s += c;
        if (node->val == tv)
            for (auto c : output)
                t += c;

        if (s != "" && t != "")
            return;

        if (node->left)
        {
            output.push_back('L');
            DFS(node->left, sv, tv);
            output.pop_back();
        }
        if (node->right)
        {
            output.push_back('R');
            DFS(node->right, sv, tv);
            output.pop_back();
        }
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        // bruteforce to find path from root to start and dest Nodes
        DFS(root, startValue, destValue);

        // Eg: s = "LLL" and "LRL"
        // since they have first L in common. It wouldn't be considered in shortest path
        // Ignore common prefix and start from LCA(lowest Common Ancestor)
        int i = 0;
        while (i < s.size() && i < t.size() && s[i] == t[i])
            i++;

        // Now from start to LCA will only be "U", so replace remeaning s with U
        // And from LCA to dest, add uncommon path to ans, as it is
        // Hence 'LL' and 'RL' makes 'UURL' as path

        // Edge case, if one is the parent of other
        // Say s = '' (is root) and t = 'L'
        // in that case, 1. remove common prefix. If one path ends. It's also considered as uncommon
        // 2. Remaining uncommon left to U => '' and right as it is => 'L'. Hence, ans => 'L'
        string ans = "";
        for (int j = i; j < s.size(); j++)
            ans += 'U';
        for (int j = i; j < t.size(); j++)
            ans += t[j];
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    int startValue = 3;
    int destValue = 6;

    cout << sol.getDirections(root, startValue, destValue) << endl;
    return 0;
}

// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
