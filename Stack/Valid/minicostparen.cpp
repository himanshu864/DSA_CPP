#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    // push string into stack and pop matching brackets
    stack<char> s;
    for (char c : str)
    {
        if (c == '}' && s.size() && s.top() == '{')
            s.pop();
        else
            s.push(c);
    }

    // for odd stack, not possible
    if (s.size() % 2)
        return -1;

    // for even, keep matching pairs, if both same, reverse one, else have to reverse both.
    int ans = 0;
    while (s.size())
    {
        char right = s.top();
        s.pop();
        if (s.top() != right)
            ans++;
        ans++;
        s.pop();
    }
    return ans;
}

int main()
{
    // string str = "{{}";
    // string str = "{}}{}}";
    // string str = "{{{}}";
    // string str = "{{{{";
    // string str = "}}{{";
    string str = "{}}}{}{{{}";
    // string str = "}}}}}{";
    cout << findMinimumCost(str) << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770
