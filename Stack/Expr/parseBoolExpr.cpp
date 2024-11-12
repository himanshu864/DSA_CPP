#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> s;
        for (char c : expression)
        {
            if (c == ')')
            {
                bool NOT = false;
                bool OR = false;
                bool AND = true;

                while (s.top() != '!' && s.top() != '|' && s.top() != '&')
                {
                    bool flag = s.top() == 't' ? true : false;
                    NOT = !flag;
                    OR |= flag;
                    AND &= flag;
                    s.pop();
                }

                bool ans = (s.top() == '!' ? NOT : (s.top() == '|' ? OR : AND));
                s.pop();
                s.push(ans ? 't' : 'f');
            }
            else if (c == '(' || c == ',')
                continue;
            else
                s.push(c);
        }
        return s.top() == 't' ? true : false;
    }
};

int main()
{
    Solution sol;
    // string expression = "|(!(t))";
    // string expression = "&(t,!(f))";
    string expression = "|(f,&(t,t))";
    cout << (sol.parseBoolExpr(expression) ? "t" : "f") << endl;
    return 0;
}

// https://leetcode.com/problems/parsing-a-boolean-expression/
