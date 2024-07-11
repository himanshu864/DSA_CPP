#include <iostream>
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

// Since inorder is sorted. Apply two pointer approach using BST Iterators
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> next, before;
        TreeNode *temp = root;
        while (temp)
        {
            next.push(temp);
            temp = temp->left;
        }

        temp = root;
        while (temp)
        {
            before.push(temp);
            temp = temp->right;
        }

        while (next.top() != before.top())
        {
            if (next.top()->val + before.top()->val == k)
                return k;
            else if (next.top()->val + before.top()->val > k)
            {
                temp = before.top()->left;
                before.pop();
                while (temp)
                {
                    before.push(temp);
                    temp = temp->right;
                }
            }
            else
            {
                temp = next.top()->right;
                next.pop();
                while (temp)
                {
                    next.push(temp);
                    temp = temp->left;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int k = 9;
    cout << (sol.findTarget(root, k) ? "Yes" : "No") << endl;
    return 0;
}

// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
