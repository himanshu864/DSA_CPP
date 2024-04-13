#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q;

    MyStack() {}

    // queue pushed from top(rear) and popped from bottom(front)
    // but stack both pushed and pops from bottom
    // if we put 1 -> 2 -> 3 into both
    // stack pops as : 3 -> 2 -> 1 (Last-In comes out first)
    // while queue as: 1 -> 2 -> 3 (First-In comes out First)

    // If somehow we can make queue push to bottom, our problem will be solved
    // In that case, queue will store values in reversed order, and will pop similar to stack

    // To do that, we can either use another queue extra to shift values easily
    // void push(int x)
    // {
    //     extra.push(x);
    //     while (main.size()) {
    //         extra.push(main.front());
    //         main.pop();
    //     }
    //     swap(main, extra);
    // }

    // For push x, and then push bottom to top and pop upto x
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        while (n--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    bool empty() { return q.empty(); }
};

int main()
{
    MyStack st;
    cout << "Is empty: " << st.empty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Popped value: " << st.pop() << endl;
    cout << "Top: " << st.top() << endl;
    st.push(4);
    cout << "Top: " << st.top() << endl;

    return 0;
}

// https://leetcode.com/problems/implement-stack-using-queues/
