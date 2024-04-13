#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node *createBT(vector<int> &nums)
{
    queue<Node *> q;
    Node *root = new Node(0);
    q.push(root);
    while (q.size())
    {
        Node *parent = q.front();
        int i = parent->data;
        if ((2 * i + 1) < nums.size() && nums[2 * i + 1] != -1)
        {
            Node *lchild = new Node(2 * i + 1);
            q.push(lchild);
            parent->left = lchild;
        }
        if ((2 * i + 2) < nums.size() && nums[2 * i + 2] != -1)
        {
            Node *rchild = new Node(2 * i + 2);
            q.push(rchild);
            parent->right = rchild;
        }
        q.pop();
    }
    return root;
}

int main()
{
    vector<int> nums = {5, 8, 6, -1, 9, 3, -1, -1, -1, 4, 2};
    Node *root = createBT(nums);
    cout << nums[root->data] << endl;
    cout << nums[root->left->right->left->data] << endl;
    return 0;
}
