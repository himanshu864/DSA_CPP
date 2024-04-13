#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;   // data inside linked list
    Node *next; // pointer storing address of and pointing to next node

    // constructors to avoid garbage value
    Node() : data(0), next(nullptr) {}
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructure
    // ~Node()
    // {
    //     // delete memory
    //     if (this->next != NULL)
    //     {
    //         this->next = NULL;
    //         delete next;
    //     }
    // }
};

void print(Node *&head)
{
    Node *temp = head; // create a temp node pointing to head
    while (temp != NULL)
    {
        cout << temp->data << " "; // print it's data and
        temp = temp->next;         // iterate it next position by changing address to next
    }
    cout << endl;
}

Node *arrtoLL(vector<int> &nums)
{
    Node *dummy = new Node();
    Node *it = dummy;
    for (int i : nums)
    {
        it->next = new Node(i);
        it = it->next;
    }
    return dummy->next;
}

void insertHead(Node *&head, int d)
{
    Node *temp = new Node(d); // create a new Node object with given data d
    temp->next = head;        // and set it's next pointer to the current head of the list
    head = temp;              // now, update head pointer to point to the newly created note
}

void insertTail(Node *&head, int d)
{
    Node *tail = head;
    while (tail->next != NULL) // just traverse to tail
        tail = tail->next;

    Node *temp = new Node(d);
    tail->next = temp;
}

void insertPosition(Node *&head, int pos, int d)
{
    Node *temp = new Node(d);
    if (pos == 1) // exactly the same as inserthead
    {
        temp->next = head;
        head = temp;
        return;
    }
    if (head == NULL) // for empty and non head
        return;

    Node *prev = head;
    for (int i = 1; i < pos - 1; i++) // traverse to (n - 1)th position node
    {
        prev = prev->next;
        if (prev == NULL)
            return;
    }
    temp->next = prev->next; // link new node next to address of nth node
    prev->next = temp;       // then change next of new node to address of (n-1)th node
}

void deletenode(Node *&head, int pos)
{
    if (head == NULL) // for empty node
        return;

    Node *temp = head;
    if (pos == 1) // if pos is head
    {
        head = head->next;
        delete (temp);
        return;
    }

    Node *prev = NULL;
    for (int i = 1; i < pos; i++)
    {
        if (temp->next == NULL) // if pos out of bounds
            return;
        prev = temp;
        temp = temp->next;
    }
    prev->next = prev->next->next;
    delete (temp);
}

int main()
{
    Node *node1 = new Node(10);
    cout << "Data: " << node1->data << " Next: " << node1->next << endl;

    Node *head = NULL;

    cout << "- Inserting head... " << endl;
    insertHead(head, 12);
    print(head);
    insertHead(head, 15);
    print(head);
    cout << "Head: " << head->data << endl;

    cout << "- Inserting tail... " << endl;
    insertTail(head, 20);
    print(head);
    insertTail(head, 8);
    print(head);
    cout << "Head: " << head->data << endl;

    cout << "- Inserting at position... " << endl;
    insertPosition(head, 3, 55);
    print(head);
    insertPosition(head, 1, 77);
    print(head);
    insertPosition(head, 7, 99);
    print(head);
    cout << "Head: " << head->data << endl;

    cout << "- Deletion at Positions... " << endl;
    deletenode(head, 1);
    print(head);
    deletenode(head, 6);
    print(head);
    deletenode(head, 4);
    print(head);
    cout << "Head: " << head->data << endl;
    return 0;
}
