#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1;
    stack<int> s2;
    int last;

public:
    void push(int x)
    {
        // push all elements from s1 to s2 (reverse)
        last = x;
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // push x in s1
        s1.push(x);

        // push back s2 to s1 (revert)
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        s1.pop();
    }
    int front()
    {
        return s1.top();
    }
    int back()
    {
        if (s1.size() == 0)
            return -1;
        return last;
    }
    int size()
    {
        return s1.size();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (q.size())
    {
        cout << q.front() << " " << q.back() << " " << q.size() << endl;
        q.pop();
    }
    return 0;
}
