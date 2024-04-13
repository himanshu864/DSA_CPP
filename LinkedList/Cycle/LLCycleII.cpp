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

ListNode *detectCycle(ListNode *head)
{
    if (!head || !(head->next))
        return NULL;
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while (fast != slow)
    {
        if (!fast || !(fast->next))
            return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *temp = head;
    while (temp != fast)
    {
        temp = temp->next;
        fast = fast->next;
    }
    return fast;
}
// Floyd's heir and tortoise algo:
// then move head and node together
// intersection will be the starting point of cycle

int main()
{
    vector<int> nums = {3, 2, 0, 4};
    ListNode *head = arrtoLL(nums);
    print(head);

    // make it a looop baby girl
    head->next->next->next->next = head->next;
    ListNode *ans = detectCycle(head);
    cout << "Start of cycle: " << ans->val << endl;
    return 0;
}
