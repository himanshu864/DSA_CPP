#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
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

// Morris Inorder traversal with T.C = O(N) + O(N)[anamotized], and no space complexity
// Traverse to left, with node and then traverse to right
// If no left, print node and move to right
// Make connect righest node to the root of that subtree and move to left
// If connection exist, Delete connection, print node, and move to right
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *temp = root;
        while (temp)
        {
            if (!temp->left)
            {
                ans.push_back(temp->val);
                temp = temp->right;
            }
            else
            {
                TreeNode *rightest = temp->left;
                while (rightest->right && rightest->right != temp)
                    rightest = rightest->right;

                if (rightest->right == temp)
                {
                    rightest->right = NULL;
                    ans.push_back(temp->val); // print node before making connection for preorder1
                    temp = temp->right;
                }
                else
                {
                    rightest->right = temp;
                    temp = temp->left;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(2);

    vector<int> ans = sol.inorderTraversal(root);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/
