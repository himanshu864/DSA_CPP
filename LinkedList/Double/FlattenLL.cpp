#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

void printList(Node *head)
{
    Node *parents = head;
    while (parents)
    {
        Node *children = parents;
        while (children)
        {
            cout << children->data << " ";
            children = children->child;
        }
        parents = parents->next;
        cout << endl;
    }
}

// merge last two parents
Node *merge2sorted(Node *head1, Node *head2)
{
    Node *ans = new Node();
    Node *it = ans;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data <= temp2->data)
        {
            it->child = temp1;
            temp1 = temp1->child;
        }
        else
        {
            it->child = temp2;
            temp2 = temp2->child;
        }
        it = it->child;
    }
    if (temp1)
        it->child = temp1;
    if (temp2)
        it->child = temp2;
    return ans->child;
}

// recursively keep merge last two parents until one left
// Can also do the same iteratively lol

Node *flattenLinkedList(Node *head)
{
    if (!head || !(head->next))
        return head;

    Node *temp = flattenLinkedList(head->next);
    head->next = NULL; // very important
    return merge2sorted(temp, head);
}

int main()
{
    Node *head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);
    head->next = new Node(4);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);
    head->next->next = new Node(7);
    head->next->next->child = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->child = new Node(12);
    head->next->next->next->next = new Node(20);

    cout << "Original linked list as child-right parent-down:" << endl;
    printList(head);
    cout << endl;

    head = flattenLinkedList(head);

    cout << "Flattened linked list:" << endl;
    printList(head);
    cout << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655
// https://leetcode.com/problems/merge-k-sorted-lists/
