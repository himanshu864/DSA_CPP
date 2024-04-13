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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode();
    ListNode *it = head;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        ListNode *temp = new ListNode(sum % 10);
        it->next = temp;
        it = temp;
    }
    return head->next;
}

int main()
{
    vector<int> nums1 = {2, 4, 3, 0, 9};
    vector<int> nums2 = {5, 6, 4, 0, 5};
    ListNode *l1 = arrtoLL(nums1);
    ListNode *l2 = arrtoLL(nums2);
    ListNode *ans = addTwoNumbers(l1, l2);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/add-two-numbers/
