#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int ans = 0;

        if (x > y)
        {
            ans += removeAndCount(s, 'a', 'b', x);
            ans += removeAndCount(s, 'b', 'a', y);
        }
        else
        {
            ans += removeAndCount(s, 'b', 'a', y);
            ans += removeAndCount(s, 'a', 'b', x);
        }

        return ans;
    }

private:
    int removeAndCount(string &s, char first, char second, int points)
    {
        int count = 0;
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty() && st.top() == first && c == second)
            {
                st.pop();
                count += points;
            }
            else
                st.push(c);
        }

        // Rebuild the string without the removed pairs
        string temp;
        while (!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;

        return count;
    }
};

int main()
{
    Solution sol;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    cout << sol.maximumGain(s, x, y);
    return 0;
}

// https://leetcode.com/problems/maximum-score-from-removing-substrings
