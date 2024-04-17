#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

class Codec
{
    TreeNode *helper(queue<string> &q)
    {
        // Again preorder traversal queue
        // and recursively attach root left right
        string x = q.front();
        q.pop();

        if (x == "*")
            return NULL;

        TreeNode *root = new TreeNode(stoi(x));
        root->left = helper(q);
        root->right = helper(q);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // easy convert string by preorder traversal
        // use comma necassary as multiple digit interger and negative signs
        if (!root)
            return "*";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // don't know how to use stringstream
        // convert string to queue, separated by comma
        queue<string> q;
        string s = "";
        for (char c : data)
        {
            if (c == ',')
            {
                q.push(s);
                s = "";
            }
            else
                s += c;
        }
        if (s.size())
            q.push(s);

        return helper(q);
    }
};

int main()
{
    Codec ser, deser;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    levelOrder(root);

    cout << ser.serialize(root) << endl;

    TreeNode *ans = deser.deserialize(ser.serialize(root));
    levelOrder(ans);

    return 0;
}

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
