#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans;

    for (char c : s)
    {
        if (isalnum(c))
            ans += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(c) < prec(st.top()) ||
                   !st.empty() && prec(c) == prec(st.top()) &&
                       associativity(c) == 'L')
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string post = infixToPostfix(exp);
    cout << post << endl;
    return 0;
}
