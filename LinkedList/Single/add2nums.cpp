#include <bits/stdc++.h>
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

void printLL(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << '\n';
}

ListNode *arrtoLL(vector<int> &nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *it = head;
    for (int i : nums)
    {
        ListNode *temp = new ListNode(i);
        it->next = temp;
        it = it->next;
    }
    return head;
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {2, 4, 3, 0, 9};
    vector<int> nums2 = {5, 6, 4, 0, 5};
    ListNode *l1 = arrtoLL(nums1);
    ListNode *l2 = arrtoLL(nums2);
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    printLL(ans);
    return 0;
}

// https://leetcode.com/problems/add-two-numbers/
