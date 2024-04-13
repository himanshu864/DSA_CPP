#include <iostream>
#include <stack>
using namespace std;

// notice how outside and inside stack prec. automatically takes care of L-R & R-L associativity
// also how they only equal in case of open and closing brackets
// simply pop stack until open bracket and don't push closing bracket in ans
// closing brackets will automatically match its opening and solve inside first by emptying stack
// directly push variables to ans to avoid errors (optional)
// anst is same as easy mod

// Not really working
int OutsideStackPre(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 7;
    return 0; // ')' out of stack precedence is 0
}

int InsideStackPre(char c)
{
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^') // power operator is from right to left precedence -
        return 5;
    else if (c == '(')
        return 0;
    return -1; // ')' wouldn't be pushed inside stack. hence dummy return;
}

string Infix_Postfix(string s)
{
    string ans = "";
    stack<char> stk;
    for (char c : s)
    {
        if (isalnum(c))
            ans += c;
        else
        {
            while (stk.size() && InsideStackPre(stk.top()) >= OutsideStackPre(c))
            {
                if (InsideStackPre(stk.top()) > OutsideStackPre(c)) // if not bracket
                    ans += stk.top();
                stk.pop();
            }
            if (c != ')')
                stk.push(c);
        }
    }
    while (stk.size())
    {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int main()
{
    // string s = "(a+b)*c-d^e^f";
    string s = "(a+b)*((c-d)^e)^f";
    cout << s << endl;
    cout << Infix_Postfix(s) << endl;
    return 0;
}
