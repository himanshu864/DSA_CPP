#include <bits/stdc++.h>
using namespace std;

// try counting on paper,
string removeOuterParentheses(string s)
{
    string ans = "";
    int temp = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
            temp--;
        if (temp > 0)
            ans += s[i];
        if (s[i] == '(')
            temp++;
    }
    return ans;
}

// lee
string removeOuterParenthese(string s)
{
    string ans = "";
    int count = 0;
    for (char x : s)
    {
        if (x == '(' && count++ > 0)
            ans += x;
        if (x == ')' && --count > 0)
            ans += x;
    }
    return ans;
}

int main()
{
    string s = "(()())((()))()";
    // string s = "(()())((()))";
    // string s = "(()())(())";
    // string s = "(())(())";
    // string s = "()(())";
    // string s = "(())";
    // string s = "()";
    cout << removeOuterParentheses(s) << endl;
    return 0;
}
