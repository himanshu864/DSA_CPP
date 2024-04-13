#include <iostream>
#include <queue>
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
        next = NULL;
        prev = NULL;
    }
};
class DequeDLL
{
public:
    Node *front;
    Node *rear;
    int size;
    int N;

    DequeDLL(int n)
    {
        front = NULL;
        rear = NULL;
        size = 0;
        N = n;
    }

    bool pushFront(int x)
    {
        if (size == N)
            return false;

        Node *temp = new Node(x);
        if (size == 0)
            rear = temp;
        else
        {
            temp->next = front;
            front->prev = temp;
        }
        front = temp;
        size++;
        return true;
    }

    bool pushRear(int x)
    {
        if (size == N)
            return false;

        Node *temp = new Node(x);
        if (size == 0)
            front = temp;
        else
        {
            temp->prev = rear;
            rear->next = temp;
        }
        rear = temp;
        size++;
        return true;
    }

    int popFront()
    {
        if (size == 0)
            return -1;
        Node *temp = front;
        front = front->next;
        if (size > 1)
        {
            front->prev = NULL;
            temp->next = NULL;
        }
        size--;
        return temp->data;
    }

    int popRear()
    {
        if (size == 0)
            return -1;
        Node *temp = rear;
        rear = rear->prev;
        if (size > 1)
        {
            rear->next = NULL;
            temp->prev = NULL;
        }
        size--;
        return temp->data;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return front->data;
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        return rear->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == N;
    }
};

int main()
{
    DequeDLL dq(5);
    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushRear(30);
    cout << dq.getFront() << endl;
    cout << dq.popRear() << endl;
    cout << dq.popRear() << endl;
    return 0;
}
