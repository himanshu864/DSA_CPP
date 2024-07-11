#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// My O(n^2) first try solution
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> st;
        st.push("");
        for (char c : s)
        {
            if (c == '(')
                st.push("");
            else if (c == ')')
            {
                string top = st.top();
                st.pop();
                reverse(top.begin(), top.end());
                st.top() += top;
            }
            else
            {
                if (st.size())
                    st.top() += c;
                else
                    st.push("" + c);
            }
        }
        return st.top();
    }
};

// Genius O(n) solution by Mr.Lee
/*
In the first pass,
use a stack to find all paired parentheses,
I assume you can do this.

Now just imgine that all parentheses are wormholes.
As you can see in the diagram,
the paired parentheses are connected to each other.

First it follows the left green arrrow,
go into the left wormhole and get out from the right wormhole.
Then it iterates the whole content between parentheses.
Finally it follows the right arrow,
go into the left wormhole,
get out from the right wormhole and finish the whole trip.

So in the second pass of our solution,
it traverses through the paired parentheses
and generate the result string res.

i is the index of current position.
d is the direction of traversing.
*/

class Solution
{
public:
    string reverseParentheses(string s)
    {
        // Hashmap parentheses pairs
        int n = s.size();
        vector<int> pair(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            if (s[i] == ')')
            {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Here comes the genius of wormhole
        string ans = "";
        for (int i = 0, d = 1; i < n; i += d)
        {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                ans += s[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "(u(love)i)";
    cout << sol.reverseParentheses(s) << endl;
    return 0;
}

// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
