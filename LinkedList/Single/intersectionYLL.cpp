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

// 3 pass : move longer to align with shorter
// ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
// {
//     int a = 0, b = 0;
//     for (ListNode *temp = headA; temp; temp = temp->next)
//         a++;
//     for (ListNode *temp = headB; temp; temp = temp->next)
//         b++;

//     ListNode *la = headA, *lb = headB;
//     if (a > b)
//         while (a-- > b)
//             la = la->next;
//     else
//         while (b-- > a)
//             lb = lb->next;

//     while (la)
//     {
//         if (la == lb)
//             return la;
//         la = la->next;
//         lb = lb->next;
//     }
//     return NULL;
// }

// move 2 pointers simultaneously, and cross when one NULL, they will align as they cover same dist
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA, *temp2 = headB;
    while (temp1 != temp2) // if initial nodes are already intersecting
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2) // if intersect or arrive at NULL at same time if no collide
            return temp1;

        // if pointer reachs NULL, place to the head of the other LL
        if (!temp1)
            temp1 = headB;
        if (!temp2)
            temp2 = headA;
    }
    return temp1;
}

int main()
{
    vector<int> numsA = {5, 6, 1, 8, 4, 5};
    vector<int> numsB = {4, 1};
    ListNode *headA = arrtoLL(numsA);
    ListNode *headB = arrtoLL(numsB);
    headB->next->next = headA->next->next->next; // join both LL's
    ListNode *intersection = getIntersectionNode(headA, headB);
    if (intersection)
        cout << intersection->val << endl;
    return 0;
}

// https://leetcode.com/problems/intersection-of-two-linked-lists/
