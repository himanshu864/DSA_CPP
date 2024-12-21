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

// Bottom Up DP - O(N2) && O(N2)
class Solution2
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<int> str = {0, 1}; // {start_index, max_length}
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // Check all substrings of length 2
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                str = {i, 2};
            }

        // Check substrings of length 3 or more
        for (int len = 3; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    str = {i, len};
                }
            }

        return s.substr(str[0], str[1]);
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
