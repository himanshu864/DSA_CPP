#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
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

// My concise Brute Force
// Check zero sum for all nodes
// Connect-Delete-and move to next if zero
class Solution2
{
    ListNode *VibeCheck(ListNode *head)
    {
        int sum = 0;
        ListNode *temp = head, *ans = head;
        while (temp)
        {
            sum += temp->val;
            temp = temp->next;
            if (sum == 0)
                ans = temp;
        }
        return ans;
    }

public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *it = dummy;
        while (it && it->next)
        {
            it->next = VibeCheck(it->next);
            it = it->next;
        }
        return dummy->next;
    }
};

// Kindof optimal using hashmaps
// Store prefix and ListNodes in hashmap and delete-connect-move on to next if same prefix
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        unordered_map<int, ListNode *> mp = {{0, dummy}};

        int sum = 0;
        ListNode *temp = head;
        while (temp)
        {
            sum += temp->val; // current prefix
            if (!mp.count(sum))
                mp[sum] = temp; // if new, add
            else
            {
                // else, remove all values from hashmap from
                // that prefix node to curr node
                // Don't iterate randomly through unordered_map
                int x = sum;
                ListNode *it = mp[sum]->next;
                while (it != temp)
                {
                    x += it->val;
                    mp.erase(x);
                    it = it->next;
                }
                // finally connect that prefix first node to
                // next node of current temp to delete elements with zero sum
                mp[sum]->next = temp->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution sol;
    // vector<int> arr = {1, 2, 3, -3, -2, -3, 4};
    vector<int> arr = {-2, -1, 1, -1, 1, -1, 2};
    ListNode *head = arrtoLL(arr);
    printLL(head);

    head = sol.removeZeroSumSublists(head);
    printLL(head);
    return 0;
}

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
