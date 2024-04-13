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

// to check working
Node *reverseDLL(Node *head)
{
    while (head->next)
    {
        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        head = temp;
    }
    head->next = head->prev;
    head->prev = NULL;
    return head;
}

Node *deleteAllOccurrences(Node *head, int k)
{
    if (!head)
        return NULL;

    Node *dummy = new Node(0, head, NULL);
    Node *temp = dummy;
    while (temp)
    {
        Node *idk = temp;
        while (temp->next && temp->next->data == k)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
        if (temp)
            temp->prev = idk;
    }
    Node *newHead = dummy->next;
    if (newHead)
        newHead->prev = NULL;
    return newHead;
}

int main()
{
    // vector<int> nums = {10, 4, 10, 3, 5, 20, 10};
    vector<int> nums = {10, 10, 10, 10, 10};
    Node *head = arrtoDLL(nums);
    print(head);
    int k = 10;
    head = deleteAllOccurrences(head, k);
    cout << "Deleting all " << k << "'s..." << endl;
    print(head);
    cout << "Reversing..." << endl;
    head = reverseDLL(head);
    print(head);
    cout << "Working!!" << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461
