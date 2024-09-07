#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool dfs(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (!root)
            return false;
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (!root)
            return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

int main()
{
    Solution sol;

    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(3);

    cout << sol.isSubPath(head, root);
    return 0;
}

// https://leetcode.com/problems/linked-list-in-binary-tree/
