#include <iostream>
#include <vector>
using namespace std;

// Best Tabulation
class Solution
{
    // here dp[i][j] doesn't represent longestCommonSubstr between s1[i] and s2[j]
    // but represents length current common substring b/w s1[0->i] & s2[0->j]
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int ans = 0;
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
        return ans;
    }
};

// Recursion
class Solution2
{
    int f(int i, int j, string &s, string &t)
    {
        if (i < 0 || j < 0)
            return 0;

        if (s[i] == t[j])
        {
            int count = 0;
            while (i >= 0 && j >= 0 && s[i] == t[j])
                i--, j--, count++;
            return max(count, f(i, j, s, t));
        }
        return max(f(i - 1, j, s, t), f(i, j - 1, s, t));
    }

public:
    int longestCommonSubstr(string str1, string str2)
    {
        return f(str1.size() - 1, str2.size() - 1, str1, str2);
    }
};

int main()
{
    Solution2 sol;
    string str1 = "ABCDGH";
    string str2 = "ACDGHR";
    cout << sol.longestCommonSubstr(str1, str2) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
