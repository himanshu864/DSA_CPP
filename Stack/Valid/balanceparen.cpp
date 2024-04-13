#include <iostream>
using namespace std;

class Stack
{
    char *data;
    int capacity;
    int idx;

public:
    Stack(int size)
    {
        capacity = size;
        data = new char[capacity];
        idx = -1;
    }
    char top()
    {
        if (idx == -1)
            return -1;
        return data[idx];
    }
    void push(char x)
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

bool checkBalance(string str)
{
    Stack temp(100);
    for (char c : str)
    {
        if (c == '(')
            temp.push(')');
        else if (c == '{')
            temp.push('}');
        else if (c == '[')
            temp.push(']');
        else if (c == ')' || c == '}' || c == ']')
        {
            if (temp.empty() || temp.top() != c)
                return false;
            temp.pop();
        }
    }
    return temp.empty();
}

int main()
{
    string str = "{([a + b] * [c - d] / e}";
    checkBalance(str) ? printf("Valid") : printf("Unvalid");
    return 0;
}
