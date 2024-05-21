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

    while (!q.empty())
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

TreeNode *arrtoBT(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    int n = nums.size();
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(nums[0]);
    q.push(root);
    for (int i = 0; i < n; i++)
    {
        TreeNode *p = q.front();
        int l = 2 * i + 1, r = 2 * i + 2;
        q.pop();

        if (l < n && nums[l] != -1)
        {
            p->left = new TreeNode(nums[l]);
            q.push(p->left);
        }
        if (r < n && nums[r] != -1)
        {
            p->right = new TreeNode(nums[r]);
            q.push(p->right);
        }
    }
    return root;
}

void insert(vector<int> &heap, int x)
{
    heap.push_back(x);
    int i = heap.size() - 1;
    while (i && heap[i] > heap[(i - 1) / 2])
    {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main()
{
    vector<int> heap = {30, 20, 15, 5, 10, 12, 6};
    int x = 40;
    insert(heap, x);
    TreeNode *root = arrtoBT(heap);
    levelOrder(root);
    return 0;
}
