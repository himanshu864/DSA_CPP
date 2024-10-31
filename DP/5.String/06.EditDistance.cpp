#include <iostream>
#include <vector>
using namespace std;

// Recursion - O(3^n)
class Solution1
{
    int helper(int i, int j, string &s, string &t)
    {
        if (j == t.size()) // delete remaining s[i -> end]
            return s.size() - i;
        if (i == s.size()) // insert remaining t[j -> end]
            return t.size() - j;

        if (s[i] == t[j])
            return helper(i + 1, j + 1, s, t);

        int insert = helper(i, j + 1, s, t);
        int del = helper(i + 1, j, s, t);
        int replace = helper(i + 1, j + 1, s, t);
        return 1 + min({insert, del, replace});
    }

public:
    int minDistance(string word1, string word2)
    {
        return helper(0, 0, word1, word2);
    }
};

// Memoization
class Solution2
{
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j == t.size())
            return s.size() - i;
        if (i == s.size())
            return t.size() - j;

        if (dp[i][j] == -1)
        {
            if (s[i] == t[j])
                dp[i][j] = helper(i + 1, j + 1, s, t, dp);
            else
            {
                int insert = helper(i, j + 1, s, t, dp);
                int del = helper(i + 1, j, s, t, dp);
                int replace = helper(i + 1, j + 1, s, t, dp);
                dp[i][j] = 1 + min({insert, del, replace});
            }
        }
        return dp[i][j];
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return helper(0, 0, word1, word2, dp);
    }
};

// Tabulation
class Solution3
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min({insert, del, replace});
                }
            }
        return dp[m][n];
    }
};

// Space Optimization
class Solution4
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1);
        for (int j = 1; j <= n; j++)
            dp[j] = j;

        for (int i = 1; i <= m; i++)
        {
            int prev = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];
                dp[j] = (word1[i - 1] == word2[j - 1]) ? prev : 1 + min({dp[j - 1], dp[j], prev});
                prev = temp;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution4 sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}

// https://leetcode.com/problems/edit-distance/
