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

// create a dummy to avoid head edge case
ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return NULL;

    ListNode *dummy = new ListNode(0, head);
    ListNode *it = dummy;
    while (it)
    {
        while (it->next && it->next->val == val)
            it->next = it->next->next;
        it = it->next;
    }
    return dummy->next;
}

// genius recursive code
ListNode *removeElements2(ListNode *head, int val)
{
    if (!head)
        return NULL;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

int main()
{
    vector<int> nums = {6, 1, 2, 6, 4, 5, 6};
    // vector<int> nums = {7, 7, 7, 7};
    ListNode *head = arrtoLL(nums);
    print(head);
    head = removeElements2(head, 6);
    print(head);
    return 0;
}

// https://leetcode.com/problems/remove-linked-list-elements/
