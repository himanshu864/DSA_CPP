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

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // check after iterating as initially same
            return true;
    }
    return false;
}
// Floyd's heir and tortoise algo:
// fast and slow difference keep decreasing by one,
// hence, they are bound to meet, if loop

int main()
{
    vector<int> nums = {3, 2, 0, 4};
    ListNode *head = arrtoLL(nums);
    print(head);
    cout << "Is Cyclic: " << (hasCycle(head) ? "Yes" : "No") << endl;

    // make it a looop baby girl
    head->next->next->next->next = head->next;
    cout << "Is Cyclic: " << (hasCycle(head) ? "Yes" : "No") << endl;
    return 0;
}

// https://leetcode.com/problems/linked-list-cycle/
