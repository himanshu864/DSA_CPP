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

Node *deleteHead(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    head = head->next;

    head->prev = NULL;
    temp->next = NULL;

    delete (temp);
    return head;
}

Node *deleteTail(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *tail = head;
    while (tail->next->next != NULL)
        tail = tail->next;

    Node *temp = tail->next;
    temp->prev = NULL;
    tail->next = NULL;

    delete (temp);
    return head;
}

Node *deletePosition(Node *&head, int pos)
{

    if (head == NULL) // empty
        return NULL;
    if (pos == 1) // head not null and position 1
        return deleteHead(head);
    if (head->next == NULL) // single but position not 1, simply return
        return head;

    Node *it = head;
    for (int i = 1; i < pos; i++)
    {
        it = it->next;
        if (it == NULL) // out of bounds
            return head;
    }
    if (it->next == NULL) // tail
        return deleteTail(head);
    // middle
    it->next->prev = it->prev;
    it->prev->next = it->next;
    it->next = NULL;
    it->prev = NULL;
    delete (it);
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *head = arrtoDLL(arr);
    print(head);
    head = deleteHead(head);
    print(head);
    head = deleteTail(head);
    print(head);
    head = deletePosition(head, 1);
    print(head);
    head = deletePosition(head, 5);
    print(head);
    head = deletePosition(head, 3);
    print(head);
    return 0;
}
