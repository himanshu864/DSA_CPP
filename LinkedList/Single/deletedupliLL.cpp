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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *back = dummy;
    ListNode *curr = dummy->next;
    while (curr)
    {
        bool flag = false;
        while (curr->next && curr->next->val == curr->val)
        {
            flag = true;
            curr->next = curr->next->next;
        }
        if (flag)
        {
            back->next = curr->next;
            curr = curr->next;
        }
        else
        {
            back = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 3, 3, 4, 4, 5};
    ListNode *head = arrtoLL(nums);
    print(head);
    head = deleteDuplicates(head);
    print(head);
    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
