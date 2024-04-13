#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")
            {
                int R = st.top();
                st.pop();
                int L = st.top();
                st.pop();

                if (x == "+")
                    st.push(L + R);
                else if (x == "-")
                    st.push(L - R);
                else if (x == "*")
                    st.push(L * R);
                else if (x == "/")
                    st.push(L / R);
            }
            else
                st.push(stoi(x));
        }
        return st.top();
    }
};

int main()
{
    Solution sol;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}

// Reverse Polish Notation - Postfix
// Polish Notation - Prefix
// truncates toward zero - round to prev int

// https://leetcode.com/problems/evaluate-reverse-polish-notation/
