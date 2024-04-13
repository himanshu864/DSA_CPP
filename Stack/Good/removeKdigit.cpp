#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        // we need to pop first k decreasing digits
        // eg : 1 4 3 2 2 9 10, we need smallest at first
        // so pop 4, 3 ans 2 as they are decreasing
        // so they must be greater than what came before it
        // and we only need to pop k digits
        // so only a monotonically increasing stack
        // hence, we pop whenever i < top()
        // no need to pop equal,
        // as there might be bigger digit later
        // doing this stack will have lowest digit at bottom
        // push them into a string and reverse

        // edge cases :
        // 1. 1234. nothing will pop
        // hence pop after operation from top,
        // as they must be largest

        // 2. preceding zeros, don't count, remove
        // 3. empty stack. return 0;
        stack<int> st;
        for (char c : num)
        {
            int i = c - '0';
            while (st.size() && st.top() > i && k-- > 0)
                st.pop();
            st.push(i);
        }

        while (st.size() && k-- > 0)
            st.pop();

        string ans = "";
        while (st.size())
        {
            char d = st.top() + '0';
            ans.push_back(d);
            st.pop();
        }

        while (ans.size() && ans.back() == '0')
            ans.pop_back();

        if (ans == "")
            return "0";

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "010432290";
    int k = 3;
    cout << sol.removeKdigits(s, k) << endl;
    return 0;
}

// https://leetcode.com/problems/remove-k-digits/
