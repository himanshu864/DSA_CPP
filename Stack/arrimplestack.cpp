#include <iostream>
using namespace std;

class Stack
{
    int *data;
    int capacity;
    int idx;

public:
    Stack(int size)
    {
        capacity = size;
        data = new int[capacity];
        idx = -1;
    }
    int top()
    {
        if (idx == -1)
            return -1;
        return data[idx];
    }
    void push(int x)
    {
        if (idx + 1 == capacity)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++idx] = x;
    }
    void pop()
    {
        if (idx == -1)
        {
            cout << "Stack underflow!" << endl;
            return;
        }
        idx--;
    }
    int size()
    {
        return idx + 1;
    }
    bool empty()
    {
        return idx == -1;
    }
    void clear()
    {
        idx = -1;
    }
};

int main()
{
    Stack st(100);
    st.push(7);
    st.push(3);
    st.push(11);
    st.push(4);
    while (st.size())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << st.empty() << endl;
    cout << st.top() << endl;

    return 0;
}
