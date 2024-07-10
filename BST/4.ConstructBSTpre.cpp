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

// big brain recursion
// based on valid bst logic
// Based on logic that left subtree will always have smaller val than root
// And right will have bigger than root, but smaller that it's parent if root's a left-childs
class Solution
{
    TreeNode *helper(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] >= bound)
            return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, bound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return helper(preorder, i, 1001);
    }
};

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

class Solution2
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

// My easy recursion
// Based on logic that inorder is actually inorder(sorted lol)
// We also know Preorder - Node L R; while Inorder - L Node R
// => First index of preorder will be root, while Left subtree will have smaller value than root
// Hence we can split Left and Right subtree based on that
// Eg : 8 5 1 7 10 12. Here 8 is root. While [5 1 7] will be on left subtree and [10, 12] on right
// Easy index and recursion to solve rest
class Solution
{
    TreeNode *helper(vector<int> &preorder, int s, int e)
    {
        if (s > e)
            return NULL;

        int x = s + 1;
        while (x < preorder.size() && preorder[x] < preorder[s])
            x++;

        TreeNode *root = new TreeNode(preorder[s]);
        root->left = helper(preorder, s + 1, x - 1);
        root->right = helper(preorder, x, e);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return helper(preorder, 0, preorder.size() - 1);
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
