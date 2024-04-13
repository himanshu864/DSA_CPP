#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *arrtoDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *it = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, it);
        it->next = temp;
        it = temp;
    }
    return head;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *insertBeforeHead(Node *&head, int val)
{
    Node *newHead = new Node(val, head, NULL);
    head->prev = newHead;
    return newHead;
}

Node *insertBeforeTail(Node *&head, int val)
{
    Node *it = head;
    while (it->next != NULL)
        it = it->next;

    Node *temp = new Node(val, it, it->prev);
    it->prev->next = temp;
    it->prev = temp;
    return head;
}

Node *insertBeforePosition(Node *&head, int val, int pos)
{
    if (pos == 1)
        return insertBeforeHead(head, val);

    Node *it = head;
    for (int i = 1; i < pos; i++)
        it = it->next;

    Node *temp = new Node(val, it, it->prev);
    it->prev->next = temp;
    it->prev = temp;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    Node *head = arrtoDLL(arr);
    print(head);
    head = insertBeforeHead(head, 5);
    print(head);
    head = insertBeforeTail(head, 7);
    print(head);
    head = insertBeforePosition(head, 9, 5);
    print(head);
    return 0;
}

// haven't checked for edge cases and nulled here
