#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *arrtoLL(vector<int> &nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *it = head;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        it->next = temp;
        it = it->next;
    }
    return head;
}

// slow is reach at middle node
// but we want node before middle
// hence, skip a step
ListNode *deleteMiddle(ListNode *head)
{
    if (!head->next)
        return NULL;
    ListNode *slow = head, *fast = head->next->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    ListNode *head = arrtoLL(nums);
    print(head);
    head = deleteMiddle(head);
    print(head);
    return 0;
}

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
