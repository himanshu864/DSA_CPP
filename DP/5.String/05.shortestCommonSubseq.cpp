#include <iostream>
#include <vector>
using namespace std;

// Best
class Solution
{
    /*
    Shortest Common Supersequence = s + t - LCS
    eg : s = "abac" & t = "cab"
    LCS = "ab"
    SCS = "cabac", which is nothing but abac+cab-ab = 4 + 3 - 2 = 5
    We can backtrack tabulated LCS grid and form SCS
    */
public:
    string shortestCommonSupersequence(string s, string t)
    {
        // Tabulate LCS using 2D DP
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        string ans = "";
        while (m && n)
        {
            if (s[m - 1] == t[n - 1])
            {
                ans += s[m - 1];
                m--, n--;
            }
            else
            {
                if (dp[m - 1][n] > dp[m][n - 1])
                    ans += s[m-- - 1];
                else
                    ans += t[n-- - 1];
            }
        }
        while (m)
            ans += s[m-- - 1];
        while (n)
            ans += t[n-- - 1];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Recursion - TLE + MLE
class Solution1
{
    string f(int i, int j, string &s, string &t)
    {
        if (i < 0 || j < 0)
            return i < 0 ? t.substr(0, j + 1) : s.substr(0, i + 1);

        if (s[i] == t[j])
            return f(i - 1, j - 1, s, t) + s[i];

        string u = f(i - 1, j, s, t) + s[i];
        string v = f(i, j - 1, s, t) + t[j];
        return u.size() < v.size() ? u : v;
    }

public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n1 = str1.size();
        int n2 = str2.size();
        return f(n1 - 1, n2 - 1, str1, str2);
    }
};

// Memoization + Backtracking
class Solution2
{
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 1 + (i < 0 ? j : i);

        if (dp[i][j] == 1e9)
        {
            if (s[i] == t[j])
                dp[i][j] = f(i - 1, j - 1, s, t, dp) + 1;
            else
            {
                int u = f(i - 1, j, s, t, dp) + 1;
                int v = f(i, j - 1, s, t, dp) + 1;
                dp[i][j] = min(u, v);
            }
        }
        return dp[i][j];
    }

public:
    string shortestCommonSupersequence(string s, string t)
    {
        // use memoized recursion to tabulate length of SCS for s1[0->i] && s2[0->j]
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 1e9));
        f(n1 - 1, n2 - 1, s, t, dp);

        // now backtrack from bottom right corner to top left following minimum path
        string ans = "";
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0)
        {
            if (s[i] == t[j])
            {
                ans = s[i] + ans;
                i--, j--;
            }
            else if ((i > 0 ? dp[i - 1][j] : 1e9) < (j > 0 ? dp[i][j - 1] : 1e9))
                ans = s[i--] + ans;
            else
                ans = t[j--] + ans;
        }
        return (i < 0 ? t.substr(0, j + 1) : s.substr(0, i + 1)) + ans;
    }
};

int main()
{
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    cout << sol.shortestCommonSupersequence(str1, str2) << endl;
    return 0;
}

// https://leetcode.com/problems/shortest-common-supersequence/
