#include <iostream>
using namespace std;

// using linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
public:
    Node *head;
    Node *rear;

    Queue()
    {
        head = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void enqueue(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    int dequeue()
    {
        if (head == NULL)
            return -1;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        return temp->data;
    }

    int front()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    while (!q.isEmpty())
        cout << q.dequeue() << endl;

    return 0;
}
