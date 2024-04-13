#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> input;
    stack<int> output;
    int store;

public:
    void push(int x)
    {
        store = x;
        input.push(x);
    }
    void pop()
    {
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        output.pop();
    }
    int front()
    {
        if (input.size() + output.size() == 0)
            return -1;
        if (output.empty())
        {
            while (input.size())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    int back()
    {
        if (input.size() + output.size() == 0)
            return -1;
        return store;
    }
    int size()
    {
        return input.size() + output.size();
    }
};

int main()
{
    Queue q;
    cout << q.front() << " " << q.back() << " " << q.size() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Pushing 1, 2, 3..." << endl;
    cout << q.front() << " " << q.back() << " " << q.size() << endl;
    q.pop();
    cout << "Popping..." << endl;
    cout << q.front() << " " << q.back() << " " << q.size() << endl;

    cout << "Pushing 4 and then..." << endl;
    q.push(4);
    cout << "Topping and popping the entire thing..." << endl;
    while (q.size())
    {
        cout << q.front() << " " << q.back() << " " << q.size() << endl;
        q.pop();
    }
    return 0;
}

// big brain usage of two stacks
// only O(N) when one stack empty (rare)
// hence, amontised O(1) time complexity
