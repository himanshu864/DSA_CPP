#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    bool isPalin(int i, string &s)
    {
        int j = s.size() - 1;
        while (i < j && s[i] == s[j])
            i++, j--;
        return i >= j;
    }
    int f(int i, string &s)
    {
        int n = s.size();
        if (i == n || isPalin(i, s))
            return 0;

        int ans = n - i - 1;
        string temp = "";
        while (i < n)
        {
            temp += s[i++];
            if (isPalin(0, temp))
                ans = min(ans, 1 + f(i, s));
        }
        return ans;
    }

public:
    int minCut(string s)
    {
        return f(0, s);
    }
};

// Memoization
class Solution2
{
    bool isPalin(int i, string &s)
    {
        int j = s.size() - 1;
        while (i < j && s[i] == s[j])
            i++, j--;
        return i >= j;
    }
    int f(int i, string &s, vector<int> &dp)
    {
        int n = s.size();
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        if (isPalin(i, s))
            return dp[i] = 0;

        int ans = n - i - 1;
        string temp = "";
        for (int j = i; j < n; j++)
        {
            temp += s[j];
            if (isPalin(0, temp))
                ans = min(ans, 1 + f(j + 1, s, dp));
        }
        return dp[i] = ans;
    }

public:
    int minCut(string s)
    {
        vector<int> dp(s.size(), -1);
        return f(0, s, dp);
    }
};

// Tabulation
class Solution3
{
    bool isPalin(int i, int j, string &s)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = -1; // 0 cuts required if i -> n - 1 palindrome
        for (int i = n - 1; i >= 0; i--)
        {
            int mini = n - i;
            for (int j = i; j < n; j++)
                if (isPalin(i, j, s))
                    mini = min(mini, 1 + dp[j + 1]);
            dp[i] = mini;
        }
        return dp[0];
    }
};

int main()
{
    Solution3 sol;
    string s = "babayaga";
    cout << sol.minCut(s) << endl;
    return 0;
}

// https://leetcode.com/problems/palindrome-partitioning-ii/
