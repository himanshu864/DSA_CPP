#include <iostream>
#include <vector>
using namespace std;

// Recursion - Exponential
class Solution1
{
    int lcs(int i, int j, string &s1, string &s2)
    {
        if (i < 0 || j < 0)
            return 0;
        if (s1[i] == s2[j])
            return 1 + lcs(i - 1, j - 1, s1, s2);
        return max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    }

public:
    int
    longestCommonSubsequence(string s1, string s2)
    {
        return lcs(s1.size() - 1, s2.size() - 1, s1, s2);
    }
};

// Memoization - O(n1 * n2) & O(n1 * n2)
class Solution2
{
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] == -1)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
            else
                dp[i][j] = max(lcs(i - 1, j, s1, s2, dp), lcs(i, j - 1, s1, s2, dp));
        }
        return dp[i][j];
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return lcs(s1.size() - 1, s2.size() - 1, s1, s2, dp);
    }
};

// Tabulation - O(n1 * n2) & O(n1 * n2)
class Solution3
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[n1][n2];
    }
};

/*
Notice in tabulation, we're using -
1. Prev row of same col dp[i - 1][j] => hence require prev row dp[col]
2. same row, prev col => dp[i][j - 1] => can use same dp[col - 1]
3. prev row and prev col value => dp[i - 1][j - 1]]

=> here we're gonna have to store this value separately since we're overriding prev values
by filling from top to down and left to right. Therefore, store dp[col] for next prev usage
*/

// Space Optimized - O(n1 * n2) & O(n2)
class Solution4
{
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> dp(n2 + 1);
        for (int i = 1; i <= n1; i++)
            for (int j = 1, prev = 0; j <= n2; j++)
            {
                int temp = dp[j];
                if (s1[i - 1] == s2[j - 1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        return dp[n2];
    }
};

int main()
{
    Solution3 sol;
    string text1 = "abcde";
    string text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-common-subsequence/
