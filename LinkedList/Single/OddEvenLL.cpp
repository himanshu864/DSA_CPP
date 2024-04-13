#include <iostream>
#include <vector>
#include <stack>
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

// odd and even indices (1-indexed)
// keep updating odd and even simultaneously
ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next || !head->next)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *link = head->next;
    while (even && even->next) // even will always be ahead
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = link;
    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = arrtoLL(nums);
    head = oddEvenList(head);
    print(head);
    return 0;
}

// https://leetcode.com/problems/odd-even-linked-list/
