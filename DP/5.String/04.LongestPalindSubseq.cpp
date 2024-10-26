#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    int f(int i, int j, string &s)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (s[i] == s[j])
            return 2 + f(i + 1, j - 1, s);
        return max(f(i + 1, j, s), f(i, j - 1, s));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        return f(0, s.size() - 1, s);
    }
};

// Memoization
class Solution2
{
    int f(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] == -1)
        {
            if (s[i] == s[j])
                dp[i][j] = 2 + f(i + 1, j - 1, s, dp);
            else
                dp[i][j] = max(f(i + 1, j, s, dp), f(i, j - 1, s, dp));
        }
        return dp[i][j];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n - 1, s, dp);
    }
};

// Tabulation
class Solution3
{
    // fill from bottom to top and left to right
    // only topRight triangle because i > j -> 0
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

// Space Optimization
class Solution4
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<int> prev(n), curr(n);
        for (int i = n - 1; i >= 0; i--)
        {
            curr[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                    curr[j] = 2 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

int main()
{
    Solution2 sol;
    string s = "bbbab";
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
