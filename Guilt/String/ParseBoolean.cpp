#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool parse_or(vector<int> &res)
    {
        int mask = 0;
        for (int i : res)
            mask |= i;
        return mask;
    }
    bool parse_and(vector<int> &res)
    {
        int mask = 1;
        for (int i : res)
            mask &= i;
        return mask;
    }

public:
    bool parseBoolExpr(string s)
    {
        stack<int> st;
        for (char i : s)
        {
            if (i == ',')
                continue;
            if (i == ')')
            {
                vector<int> res;
                while (st.top() != '&' && st.top() != '|' && st.top() != '!')
                {
                    char c = st.top();
                    st.pop();
                    if (c == 't')
                        res.push_back(1);
                    if (c == 'f')
                        res.push_back(0);
                }
                char c = st.top();
                st.pop();
                if (c == '&')
                    st.push(parse_and(res) ? 't' : 'f');
                else if (c == '|')
                    st.push(parse_or(res) ? 't' : 'f');
                else if (c == '!')
                    st.push(res[0] == 0 ? 't' : 'f');
            }
            else
                st.push(i);
        }
        return (st.top() == 't');
    }
};

int main()
{
    Solution sol;
    string expression = "!(&(f,t))";
    // string expression = "|(!(t), &(t, f), t)";
    cout << (sol.parseBoolExpr(expression) ? "True" : "False") << endl;
    return 0;
}

// https://leetcode.com/problems/parsing-a-boolean-expression/
