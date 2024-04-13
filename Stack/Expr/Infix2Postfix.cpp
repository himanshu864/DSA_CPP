#include <iostream>
#include <stack>
using namespace std;

int Precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 3;
}

string Infix_Postfix(string s)
{
    // string ans = "abc*+de/-";
    string ans = "";
    stack<char> stk;
    for (char c : s)
    {
        while (stk.size() && Precedence(stk.top()) >= Precedence(c))
        {
            ans += stk.top();
            stk.pop();
        }
        stk.push(c);
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
    // abc : 3 : L-R (optional, you can also check operator and push abc directly to ans)
    // *,/ : 2 : L-R
    // +,- : 1 : L-R
    cout << "Input expression using only +,-,*,/ operators: \n";
    string s = "a+b*c-d/e";
    cout << s << endl;
    cout << Infix_Postfix(s) << endl;
    return 0;
}

// shunting-yard algorithm
// for postfix - reverse polish notation