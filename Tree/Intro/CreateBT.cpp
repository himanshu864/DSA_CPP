#include <iostream>
#include <queue>
#include <vector>
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
    if (!root)
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

TreeNode *arrtoBT(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    int n = nums.size();
    queue<pair<TreeNode *, int>> q;
    TreeNode *root = new TreeNode(nums[0]);
    q.push({root, 0});
    while (q.size())
    {
        TreeNode *p = q.front().first;
        int i = q.front().second;
        int l = 2 * i + 1, r = 2 * i + 2;
        q.pop();

        if (l < n && nums[l] != -1)
        {
            p->left = new TreeNode(nums[l]);
            q.push({p->left, l});
        }
        if (r < n && nums[r] != -1)
        {
            p->right = new TreeNode(nums[r]);
            q.push({p->right, r});
        }
    }
    return root;
}

int main()
{
    // vector<int> heap = {30, 20, 15, 5, 10, 12, 6};
    // vector<int> heap = {30, 20, -1, 5, 10, -1, -1};
    vector<int> heap = {5, 8, 6, -1, 9, 3, -1, -1, -1, 4, 2};
    TreeNode *root = arrtoBT(heap);
    levelOrder(root);

    return 0;
}
