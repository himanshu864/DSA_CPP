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

// Add all left
// If print node, and move to right if exist
// else pop
class BSTIterator
{

public:
    stack<TreeNode *> st;

    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *root = st.top();
        int ans = root->val;
        st.pop();

        root = root->right;
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        return ans;
    }

    bool hasNext()
    {
        return st.size();
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    BSTIterator ino(root);
    cout << ino.next() << endl;
    cout << ino.next() << endl;
    cout << (ino.hasNext() ? "Yes" : "No") << endl;
    cout << ino.next() << endl;
    cout << ino.next() << endl;
    cout << (ino.hasNext() ? "Yes" : "No") << endl;
    cout << ino.next() << endl;
    cout << ino.next() << endl;
    cout << (ino.hasNext() ? "Yes" : "No") << endl;

    return 0;
}
