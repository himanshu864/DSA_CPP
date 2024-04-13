#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    q.push(NULL);

    while (q.size())
    {
        TreeNode *p = q.front();
        q.pop();
        if (p == NULL)
        {
            cout << endl;
            if (q.empty())
                break;
            q.push(NULL);
        }
        else
        {
            cout << p->val << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    cout << endl;
}

// My shit solution using striver help
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // recursion base case
        if (preorder.empty())
            return NULL;

        // first element of preorder is always the root : Root Left Right
        TreeNode *root = new TreeNode(preorder[0]);
        // Divide inorder into two parts : Left Root Right
        vector<int> inleft;
        vector<int> inright;
        bool flag = false;
        for (int i : inorder)
        {
            if (i == root->val)
                flag = true;
            else if (flag == false)
                inleft.push_back(i);
            else
                inright.push_back(i);
        }
        // Similarly divide preorder
        vector<int> preleft;
        vector<int> preright;
        int i = 1;
        while (i <= inleft.size())
            preleft.push_back(preorder[i++]);
        while (i < preorder.size())
            preright.push_back(preorder[i++]);

        // and pass lefts preorder and inorder to left, recursion will divide and solve that subtree, just connect it's head to root's left
        root->left = buildTree(preleft, inleft);
        // same for right
        root->right = buildTree(preright, inright);
        return root;
    }
};

// Better optimized solution using indexes
class Solution2
{
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie, unordered_map<int, int> &mp)
    {
        if (ps > pe || is > ie)
            return NULL;

        TreeNode *root = new TreeNode(preorder[ps]);
        int i = mp[preorder[ps]];
        root->left = helper(preorder, inorder, ps + 1, ps - is + i, is, i - 1, mp);
        root->right = helper(preorder, inorder, ps - is + i + 1, pe, i + 1, ie, mp);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        if (n == 0)
            return NULL;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return helper(preorder, inorder, 0, n - 1, 0, n - 1, mp);
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = sol.buildTree(preorder, inorder);

    cout << "Verify level by level:" << endl;
    levelOrder(root);

    return 0;
}
