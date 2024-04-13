#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// not solve with constant space and linear runtime

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

// TC: O(2N) and SC: O(N/2); using stack
// bool isPalindrome2(ListNode *head)
// {
//     if (head->next == NULL)
//         return true;
//     int n = 0;
//     ListNode *dumb = head;
//     while (dumb)
//     {
//         n++;
//         dumb = dumb->next;
//     }
//     stack<int> store;
//     ListNode *it = head;
//     for (int i = 1; i <= (n / 2); i++)
//     {
//         store.push(it->val);
//         it = it->next;
//     }
//     if (n % 2)
//         it = it->next;
//     while (it)
//     {
//         if (it->val != store.top())
//             return false;
//         store.pop();
//         it = it->next;
//     }
//     return true;
// }

// reverse 2nd half and compare : Heir-tortoise
ListNode *reverse(ListNode *&head)
{
    if (!head || !(head->next))
        return head;
    ListNode *newHead = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    // heir and tortoise method to find mid
    // move fast by 2 and tortoise by one
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // element next to slow will be head of the second half
    ListNode *tail = reverse(slow->next); // reverse second half
    ListNode *left = head;
    ListNode *right = tail;
    while (right) // draw diagram to understand
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    slow->next = reverse(tail); // revert changes back (Optional)
    return true;
}

int main()
{
    vector<int> nums = {1, 2, 0, 2, 1};
    // vector<int> nums = {2, 4, 3, 0, 9};
    ListNode *head = arrtoLL(nums);
    print(head);
    cout << "Is palindrome: " << (isPalindrome(head) ? "Yes" : "No") << endl;
    print(head);
    return 0;
}

// https://leetcode.com/problems/palindrome-linked-list/
