#include <iostream>
#include <vector>
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

void inorder(TreeNode *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/*
1. Create an empty stack.
2. Create a root node using the first element of the preorder traversal. Push the root node onto the stack.
3. Initialize the root node as the current node.
4. For each element in the preorder traversal (starting from the second element):
    - Create a new node with the current element.
    - If the current element is smaller than the value of the stack's top node, make it the left child of the current node and push it onto the stack. Update the current node to the newly created left child.
    - If the current element is greater than the value of the stack's top node, keep popping elements from the stack until either the stack is empty or the value of the stack's top node is greater than the current element. Make the new node the right child of the last popped node. Push the new node onto the stack and update the current node to the newly created right child.
5. Return the root of the constructed BST.
*/

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        stack<TreeNode *> st;
        int i = 1;
        while (i < preorder.size())
        {
            if (preorder[i] < p->val)
            {
                p->left = new TreeNode(preorder[i++]);
                st.push(p);
                p = p->left;
            }
            else
            {
                if (st.size() && (preorder[i] > st.top()->val))
                {
                    p = st.top();
                    st.pop();
                }
                else
                {
                    p->right = new TreeNode(preorder[i++]);
                    p = p->right;
                }
            }
        }
        return root;
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode *root = sol.bstFromPreorder(preorder);

    inorder(root);
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
