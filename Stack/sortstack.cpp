#include <iostream>
#include <stack>
using namespace std;

void ProperPush(stack<int> &stack, int x)
{
    if (stack.empty() || stack.top() <= x)
    {
        stack.push(x);
        return;
    }
    int temp = stack.top();
    stack.pop();
    ProperPush(stack, x);
    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty() || stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    ProperPush(stack, temp);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

    // print in increasing order, only recursion hence no loop
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/sort-a-stack_985275
