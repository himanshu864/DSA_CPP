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
    for (ListNode *temp = head; temp != NULL; temp = temp->next)
        cout << temp->val << " ";
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *ans = new ListNode();
    ListNode *it = ans;
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    while (temp1 && temp2)
    {
        if (temp1->val <= temp2->val)
        {
            it->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            it->next = temp2;
            temp2 = temp2->next;
        }
        it = it->next;
    }
    if (temp1)
        it->next = temp1;
    if (temp2)
        it->next = temp2;
    return ans->next;
}

// merge sort
ListNode *sortList(ListNode *head)
{
    if (!head || !(head->next))
        return head;

    // find first middle
    ListNode *slow = head, *fast = head;
    while (fast && fast->next && fast->next->next)
        slow = slow->next, fast = fast->next->next;

    // find second middle = head of second half
    ListNode *second = slow->next;
    slow->next = NULL;

    // break down list to single element. and merge sort them
    head = sortList(head);
    second = sortList(second);
    head = mergeTwoLists(head, second);
    return head;
}

int main()
{
    vector<int> arr = {4, 2, 1, 3};
    ListNode *head = arrtoLL(arr);
    print(head);
    head = sortList(head);
    print(head);
    return 0;
}

// https://leetcode.com/problems/sort-list/
