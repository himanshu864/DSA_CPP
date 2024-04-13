#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
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

// My code with tail postprocessing
Node *reverseDLL(Node *head)
{
    while (head->next)
    {
        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        head = temp;
    }
    head->next = head->prev; // head is tail now, just deal with it
    head->prev = NULL;
    return head;
}

// We keep swapping next and prev as we iterate
Node *reverseDLL2(Node *head)
{
    if (head->next == NULL)
        return head;

    Node *back = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        back = temp->prev;       // to store prev
        temp->prev = temp->next; // swap next and prev
        temp->next = back;
        temp = temp->prev; // to iterate as prev is next now
    }
    return back->prev; // draw LL to understand this one
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    Node *head = arrtoDLL(nums);
    head = reverseDLL(head);
    print(head);
    return 0;
}

// https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098
