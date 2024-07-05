#include <iostream>
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

// We traverse childs first (post-order traversal), and return the balance of coins.
// For example, if we get '+3' from the left child, that means that the left subtree has 3 extra coins to move out.
// If we get '-1' from the right child, we need to move 1 coin in. So, we increase the number of moves by 4
// (3 moves out left + 1 moves in right). We then return the final balance:
// r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).

class Solution
{
    int helper(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(0);

    cout << sol.distributeCoins(root) << endl;
    return 0;
}

// https://leetcode.com/problems/distribute-coins-in-binary-tree/
