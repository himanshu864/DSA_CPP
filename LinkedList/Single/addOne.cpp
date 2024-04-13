#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *arrtoLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *it = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        it->next = temp;
        it = it->next;
    }
    return head;
}

// 3 pass Approach: reverse list, then add one like add2num, and reverse list again

// Recursive Approach: add carry change in return time : backtracking mf
int helper(Node *head)
{
    if (!head)
        return 1;

    int carry = helper(head->next);
    if (carry == 0)
        return 0;

    int sum = head->data + carry;
    head->data = sum % 10;
    return (sum / 10);
}

Node *addOne(Node *head)
{
    if (!head)
        return head;
    int carry = helper(head);
    if (carry)
        return new Node(carry, head);
    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    // vector<int> nums = {9, 9, 9, 9};
    Node *head = arrtoLL(nums);
    print(head);
    head = addOne(head);
    print(head);
    return 0;
}

// https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557
