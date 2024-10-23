#include <iostream>
#include <vector>
#include <set>
using namespace std;

// My backtracking
class Solution1
{
    string output = "";
    set<string> seq;

    void helper(int i, int j, string &s, string &t)
    {
        if (i == s.size() || j == t.size())
        {
            if (seq.empty() || (*seq.begin()).size() == output.size())
                seq.insert(output);
            else if ((*seq.begin()).size() < output.size())
            {
                seq.clear();
                seq.insert(output);
            }
            return;
        }

        if (s[i] == t[j])
        {
            output += s[i];
            helper(i + 1, j + 1, s, t);
            output.pop_back();
        }
        else
        {
            helper(i, j + 1, s, t);
            helper(i + 1, j, s, t);
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        helper(0, 0, s, t);
        vector<string> ans(seq.begin(), seq.end());
        return ans;
    }
};

// Re-using LCS 2D Tabulation Solution
class Solution2
{
    set<string> seq;

    // 1-indexed
    void helper(int i, int j, string output, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            seq.insert(output);
            return;
        }
        if (s[i - 1] == t[j - 1])
            helper(i - 1, j - 1, s[i - 1] + output, s, t, dp);
        else
        {
            int maxi = max(dp[i - 1][j], dp[i][j - 1]);
            if (dp[i - 1][j] == maxi)
                helper(i - 1, j, output, s, t, dp);
            if (dp[i][j - 1] == maxi)
                helper(i, j - 1, output, s, t, dp);
        }
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        // 1. Tabulate 2D Grid to store lcm length per index
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
                dp[i][j] = s[i - 1] == t[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);

        // 2. Use dp[][] to backtrack all strings
        helper(n1, n2, "", s, t, dp);

        // 3. Print Answer
        vector<string> ans(seq.begin(), seq.end());
        return ans;
    }
};

// Still TLE because GFG sucks

int main()
{
    Solution2 sol;
    string s = "abaaa";
    string t = "baabaca";
    vector<string> ans = sol.all_longest_common_subsequences(s, t);
    for (const string &x : ans)
        cout << x << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
