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

// iterative;
ListNode *reverseList(ListNode *head)
{
    ListNode *back = NULL;
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        temp->next = back;
        back = temp;
    }
    return back;
}

// tail recursion kinda useless
ListNode *reverseList2(ListNode *head, ListNode *back = NULL)
{
    if (!head)
        return back;
    ListNode *front = head->next;
    head->next = back;
    return reverseList2(front, head);
}

// head recursion : Brilliant
ListNode *reverseList3(ListNode *head)
{
    if (!head || !(head->next))
        return head;
    ListNode *newHead = reverseList3(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode *head = arrtoLL(nums);
    print(head);
    head = reverseList3(head);
    print(head);
    return 0;
}

// https://leetcode.com/problems/reverse-linked-list/
