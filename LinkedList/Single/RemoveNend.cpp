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

// slow is n nodes behind fast
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    while (n--)
        fast = fast->next;

    if (!fast) // head when fast is null
    {
        ListNode *temp = head->next;
        head->next = NULL;
        delete head;
        return temp;
    }

    ListNode *slow = head;
    while (fast->next) // stop when fast is tail
    {
        slow = slow->next;
        fast = fast->next;
    }
    // slow is the node just before nth node from end
    ListNode *temp = slow->next;
    slow->next = temp->next;
    temp->next = NULL;
    delete temp;
    return head;
}

// two pass convert end to start
ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    ListNode *tail = head;
    int size = 1;
    while (tail->next)
    {
        size++;
        tail = tail->next;
    }
    n = size - n + 1;

    if (n == 1)
    {
        ListNode *temp = head->next;
        head->next = NULL;
        return temp;
    }

    ListNode *it = head;
    while (n-- > 2)
        it = it->next;

    ListNode *temp = it->next;
    it->next = temp->next;
    temp->next = NULL;
    return head;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;
    ListNode *head = arrtoLL(nums);
    print(head);
    cout << "n = " << n << endl;
    head = removeNthFromEnd(head, n);
    print(head);
    cout << "n = " << 4 << endl;
    head = removeNthFromEnd(head, 4);
    print(head);
    return 0;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
