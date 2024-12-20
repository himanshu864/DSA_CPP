#include <bits/stdc++.h>
using namespace std;

// Two Pointers - O(N2) & O(1)
class Solution
{
    vector<int> str = {0, 1};

    void expandCenter(string &s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            int len = j - i + 1;
            if (len > str[1])
                str = {i, len};
            i--, j++;
        }
    }

public:
    string longestPalindrome(string s)
    {
        for (int x = 1; x < s.size(); x++)
        {
            expandCenter(s, x - 1, x + 1); // odd
            expandCenter(s, x - 1, x);     // even
        }
        return s.substr(str[0], str[1]);
    }
};

// DP - O(N2) && O(N2)
class Solution2
{
    int f(string &s, vector<vector<int>> &dp, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return dp[i][j] = 1;
        if (i + 1 == j)
            return dp[i][j] = s[i] == s[j];
        if (s[i] != s[j])
            return dp[i][j] = 0;
        return dp[i][j] = f(s, dp, i + 1, j - 1);
    }

public:
    string longestPalindrome(string s)
    {
        int startIdx = 0, maxLen = 1;
        int n = s.size();
        // memoize if substr[i...j] is palindrome or not
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                dp[i][j] = f(s, dp, i, j);
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    startIdx = i;
                }
            }

        return s.substr(startIdx, maxLen);
    }
};

int main()
{
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << '\n';
    return 0;
}

// https://leetcode.com/problems/longest-palindromic-substring/
