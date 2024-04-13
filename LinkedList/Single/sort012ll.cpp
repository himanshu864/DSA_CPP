#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
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

Node *arrtoLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *it = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);
        it->next = temp;
        it = it->next;
    }
    return head;
}

Node *sortList(Node *head)
{
    Node *zero = NULL;
    Node *one = NULL;
    Node *two = NULL;

    Node *lastzero = NULL;
    Node *lastone = NULL;
    Node *lasttwo = NULL;

    Node *it = head;
    while (it)
    {
        if (it->data == 0)
        {
            if (zero == NULL)
            {
                zero = it;
                lastzero = it;
            }
            else
            {
                lastzero->next = it;
                lastzero = lastzero->next;
            }
        }
        else if (it->data == 1)
        {
            if (one == NULL)
            {
                one = it;
                lastone = it;
            }
            else
            {
                lastone->next = it;
                lastone = lastone->next;
            }
        }
        else
        {
            if (two == NULL)
            {
                two = it;
                lasttwo = it;
            }
            else
            {
                lasttwo->next = it;
                lasttwo = lasttwo->next;
            }
        }
        it = it->next;
    }

    // handling edge cases with no zeros/ones/ or twos
    Node *newHead = NULL;
    if (zero)
        newHead = zero;
    else if (one)
        newHead = one;
    else
        newHead = two;

    if (zero)
    {
        if (one)
            lastzero->next = one;
        else
            lastzero->next = two;
    }
    if (one)
        lastone->next = two;
    if (two)
        lasttwo->next = NULL;

    return newHead;
}

int main()
{
    vector<int> nums = {1, 0, 2, 1, 0, 2, 1};
    // vector<int> nums = {2, 2, 0, 0, 2, 0, 2};
    Node *head = arrtoLL(nums);
    head = sortList(head);
    print(head);
    return 0;
}

// https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937
