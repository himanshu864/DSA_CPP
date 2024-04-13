#include <iostream>
#include <stack>
using namespace std;

// this is my code bitch, It might be shit but it's 100% original
// took me 2hr to come up with a half broken approach and code it up
// what a ride, this is why I love coding
// 13/03/24 : Wednesday - Hisar, Haryana, India : 10:39PM

int givebottom(stack<int> &s, int x, int i, int N)
{
    if (i == N) // when bottom element
    {
        int bottom = s.top(); // remember bottom element for top
        s.top() = x;          // change bottom to top
        return bottom;
    }
    int store = s.top(); // store for recursion
    s.pop();
    int ans = givebottom(s, x, i + 1, N);
    s.push(store);
    return ans; // keep returning bottom
}

void reverseStack2(stack<int> &s, int N = 0, int i = 0)
{
    if (N == 0)
        N = s.size();
    if (s.empty() || s.size() == 1 || i >= N || N == 1)
        return;
    s.top() = givebottom(s, s.top(), 1, N - i); // pass current top and swap top to bottom

    int temp = s.top();
    s.pop();
    reverseStack2(s, N, i + 2);
    s.push(temp);
}

// By the book approach using recursion
void pushbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    pushbottom(s, x);
    s.push(temp);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty() || stack.size() == 1)
        return;

    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    pushbottom(stack, temp);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.push(6);

    reverseStack(s);

    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}

// https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875
