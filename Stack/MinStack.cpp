#include <iostream>
#include <stack>
using namespace std;

// One stack and a really hard to understand Min variable
class MinStack
{
public:
    stack<long long> st;
    long long mini;
    MinStack() { mini = -1; }
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if (val >= mini)
            st.push(val);
        else
        {
            st.push((2 * (val * 1LL) - mini) * 1LL); // point no. 1
            mini = val;
        }
    }
    void pop()
    {
        if (st.top() < mini)
            mini = 2 * mini - st.top(); // point no . 2
        st.pop();
    }
    int top()
    {
        if (st.top() < mini)
            return mini;
        return st.top();
    }
    int getMin() { return mini; }
};

/*
1. if val being pushed is smaller then min. We push (2 * val - min) instead and update mini;
This achieves multiple things, mainly we can retrieve prev min by reversing the formula
and it acts a flag, so that we can identity when this min is beings popped as,
    we push the sum of smallest value + (smallest - smaller value) --> smallest + (negative)
    which is always going to be smaller then new min( == smallest value)
thus we would also identity when to return mini instead of topping this altered value

2. top < mini, means this is first occurence of smallest value
we need to update mini to previous mini by reversing the formula
Initially we pushed : temp = 2 * (smallest value[new minimum]) - (smaller value[prev mini])
Now we need the smaller value[old minimum], and have (smallest value == mini) with (temp == st.top())
thus mini = 2 * mini - st.top()
*/

// use linked list, to store mini as attribute
class Node
{
public:
    Node *next;
    int data;
    int mini;
    Node(int val = 0, Node *point = NULL)
    {
        next = point;
        data = val;
        mini = INT_MAX;
    }
};
class MinStackLL
{
public:
    Node *head;
    MinStackLL() { head = new Node(); }
    void push(int val)
    {
        Node *temp = new Node(val, head);
        temp->mini = (val < head->mini) ? val : head->mini;
        head = temp;
    }
    void pop() { head = head->next; }
    int top() { return head->data; }
    int getMin() { return head->mini; }
};

// 2 stack simultaneously
class MinStackSS
{
public:
    stack<int> stk;
    stack<int> mist;
    MinStackSS() {}

    void push(int val)
    {
        stk.push(val);
        if (mist.size() && mist.top() < val)
            mist.push(mist.top());
        else
            mist.push(val);
    }
    void pop()
    {
        stk.pop();
        mist.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return mist.top(); }
};

int main()
{
    MinStack s;
    // MinStackLL s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    return 0;
}

// https://leetcode.com/problems/min-stack/
