#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    bool allStar(string &p, int j)
    {
        for (int x = 0; x <= j; x++)
            if (p[x] != '*')
                return false;
        return true;
    }

    bool f(int i, int j, string &s, string &p)
    {
        if (i < 0) // if input string gets exhausted. Remaining pattern can only be "***"
            return allStar(p, j);
        if (j < 0) // but if pattern gets exhausted, input string must also be empty
            return i < 0;

        if (s[i] == p[j] || p[j] == '?') // both character must either match
            return f(i - 1, j - 1, s, p);

        if (p[j] == '*') // or if patterns a star! We can choice to make it an empty string or add elements one by one. Return true if anyones true
            return f(i, j - 1, s, p) || f(i - 1, j, s, p);

        return false;
    }

public:
    bool isMatch(string s, string p)
    {
        return f(s.size() - 1, p.size() - 1, s, p);
    }
};

// Memoization
class Solution2
{
    bool allStar(string &p, int j)
    {
        for (int x = 0; x <= j; x++)
            if (p[x] != '*')
                return false;
        return true;
    }

    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0)
            return allStar(p, j);
        if (j < 0)
            return i < 0;

        if (dp[i][j] == -1)
        {
            if (s[i] == p[j] || p[j] == '?')
                dp[i][j] = f(i - 1, j - 1, s, p, dp);
            else if (p[j] == '*')
                dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
            else
                dp[i][j] = false;
        }
        return dp[i][j];
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return f(s.size() - 1, p.size() - 1, s, p, dp);
    }
};

// Tabulation
class Solution3
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // 1-based indexing
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // base case
        dp[0][0] = true;
        for (int j = 1; j <= n && p[j - 1] == '*'; j++)
            dp[0][j] = true;

        // Tabulation
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        return dp[m][n];
    }
};

// Space Optimization
class Solution4
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, false);

        dp[0] = true;
        for (int j = 1; j <= n && p[j - 1] == '*'; j++)
            dp[j] = true;

        for (int i = 1; i <= m; i++)
        {
            bool prod = dp[0];
            dp[0] = false;

            for (int j = 1; j <= n; j++)
            {
                bool temp = dp[j];

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[j] = prod;
                else if (p[j - 1] == '*')
                    dp[j] = dp[j - 1] || dp[j];
                else
                    dp[j] = false;

                prod = temp;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution4 sol;
    string s = "ab";
    string p = "*";
    cout << sol.isMatch(s, p) << endl;
    return 0;
}

// https://leetcode.com/problems/wildcard-matching/
