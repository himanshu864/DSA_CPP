#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) // mine
{
    stack<char> x;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
            x.push('(');
            break;
        case '[':
            x.push('[');
            break;
        case '{':
            x.push('{');
            break;
        case ')':
            if (x.size() && x.top() == '(')
                x.pop();
            else
                return false;
            break;
        case ']':
            if (x.size() && x.top() == '[')
                x.pop();
            else
                return false;
            break;
        case '}':
            if (x.size() && x.top() == '{')
                x.pop();
            else
                return false;
            break;
        }
    }
    return x.empty();
}

// bool isValid2(string s) // best
// {
//     stack<char> x;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '(')
//             x.push(')');
//         else if (s[i] == '{')
//             x.push('}');
//         else if (s[i] == '[')
//             x.push(']');
//         else if (x.empty() || x.top() != s[i])
//             return false;
//         else
//             x.pop();
//     }
//     return x.empty();
// }

int main()
{
    string s = "{()}[]";
    // string s = "{()}[(])";
    cout << isValid(s) << endl;
    return 0;
}

// https://leetcode.com/problems/valid-parentheses/
