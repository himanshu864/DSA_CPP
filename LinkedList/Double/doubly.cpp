#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void print(Node *&head)
{
    Node *it = head;
    while (it != NULL)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    int ans = 0;
    Node *it = head;
    while (it != NULL)
    {
        ans++;
        it = it->next;
    }
    return ans;
}

// just handle prev pointer as well
void insertHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertTail(Node *&tail, int val)
{
    Node *temp = new Node(val);
    temp->next = NULL;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertPosition(Node *&head, Node *&tail, int pos, int val)
{
    // head check
    if (pos == 1)
    {
        insertHead(head, val);
        return;
    }

    // iterator to (n - 1)th position's node
    Node *it = head;
    for (int i = 1; i < pos - 1; i++)
        it = it->next;

    // tail check
    if (it->next == NULL)
    {
        insertTail(tail, val);
        return;
    }

    Node *temp = new Node(val);
    // be caution as to not assign NULL from temp to this->it
    temp->next = it->next;
    temp->prev = it;
    it->next = temp;
    it->next->prev = temp;
}

void deletenode(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node *it = head;
    for (int i = 1; i < pos; i++)
        it = it->next;
    if (it->next == NULL)
    {
        tail = it->prev;
        tail->next = NULL;
        it->prev = NULL;
        delete it;
        return;
    }
}

int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << "Size: " << getLength(head) << endl;

    insertHead(head, 3);
    print(head);
    cout << "Size: " << getLength(head) << endl;

    insertTail(tail, 9);
    print(head);
    cout << "Size: " << getLength(head) << endl;

    insertPosition(head, tail, 3, 12);
    insertPosition(head, tail, 5, 12);
    insertPosition(head, tail, 1, 12);
    print(head);
    cout << "Size: " << getLength(head) << endl;

    deletenode(head, tail, 6);
    deletenode(head, tail, 1);
    // deletenode(head, tail, 3);
    print(head);
    cout << "Size: " << getLength(head) << endl;
    cout << "Head: " << head->data << " Tail: " << tail->data << endl;

    return 0;
}

// doubly linked list has prev, data and next.
