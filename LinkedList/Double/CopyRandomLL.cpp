#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void print(Node *head)
{
    for (Node *it = head; it; it = it->next)
        cout << it->val << " ";
    cout << endl;
}

// just create a new LL with similar nexts and random connection but entirely new nodes
Node *copyRandomList(Node *head)
{
    // create copy in between nodes
    for (Node *it = head; it; it = it->next)
    {
        Node *front = it->next;
        it->next = new Node(it->val);
        it = it->next;
        it->next = front;
    }

    // connect random
    for (Node *it = head; it; it = it->next->next)
        if (it->random) // to avoid NULL->next
            it->next->random = it->random->next;

    // connect middle correctly, and revert head to original
    Node *dummy = new Node(0);
    Node *ans = dummy;
    for (Node *it = head; it; it = it->next)
    {
        dummy->next = it->next;
        dummy = dummy->next;
        it->next = it->next->next;
    }
    return ans->next;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->random = head->next;
    print(head);
    Node *ans = copyRandomList(head);
    print(ans);
    // cout << ans->next->random->val << endl;
    return 0;
}

// https://leetcode.com/problems/copy-list-with-random-pointer/
