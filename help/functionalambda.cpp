#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_map<string, function<int(int, int)>> map = {
            {"+", [](int a, int b)
             { return a + b; }},
            {"-", [](int a, int b)
             { return a - b; }},
            {"*", [](int a, int b)
             { return a * b; }},
            {"/", [](int a, int b)
             { return a / b; }}};

        stack<int> stack;
        for (string &s : tokens)
        {
            if (!map.count(s))
                stack.push(stoi(s));
            else
            {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

int main()
{
    Solution sol;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}

// for lambda and functional header
