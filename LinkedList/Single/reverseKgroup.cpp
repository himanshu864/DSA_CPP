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

ListNode *reverse(ListNode *head)
{
    if (!head || !(head->next))
        return head;
    ListNode *newHead = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1 || !(head->next))
        return head;

    // use dummy for convenient pointing
    ListNode *dummy = new ListNode(0);
    ListNode *ans = dummy;

    ListNode *it = head;
    while (it)
    {
        int i = 1;
        ListNode *temphead = it; // store head of Kgroup
        for (; i < k && it->next; i++)
            it = it->next;

        // "it" is now tail of Kgroup
        ListNode *nexthead = it->next;
        if (i == k) // check if reverse possible (count nodes)
        {
            it->next = NULL;
            dummy->next = reverse(temphead); // point dummy at newhead
            dummy = temphead;
        }
        else
            dummy->next = temphead;
        it = nexthead;
    }
    return ans->next;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    // int k = 2;
    int k = 3;
    ListNode *head = arrtoLL(nums);
    print(head);
    ListNode *ans = reverseKGroup(head, k);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/
