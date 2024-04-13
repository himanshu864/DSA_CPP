#include <stdio.h>
// #include <bits/stdc++.h>

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

struct Stack
{
    int length;
    Node *head;

    Stack()
    {
        length = 0;
        head = nullptr;
    }
    void push(int x);
    void pop();
    int top();
    int size();
    bool empty();
};

void Stack::push(int x)
{
    Node *temp = new Node(x);
    if (temp == nullptr)
    {
        printf("Stack Overflow\n");
        return;
    }
    temp->next = head;
    head = temp;
    length++;
}
void Stack::pop()
{
    if (head == nullptr)
    {
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    length--;
}
int Stack::top()
{
    if (head == nullptr)
        return -1;
    return head->data;
}
int Stack::size()
{
    return length;
}
bool Stack::empty()
{
    return head == nullptr;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (s.size())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    s.empty() ? printf("Empty") : printf("Not Empty");
    return 0;
}
