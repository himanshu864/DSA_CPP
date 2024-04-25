#include <iostream>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int DP[26] = {0}, ans = 1;

        for (char &ch : s)
        {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;

            for (int j = max(0, i - k); j <= min(25, i + k); j++)
                if (j != i)
                    DP[i] = max(DP[i], DP[j] + 1);

            ans = max(ans, DP[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "acfgbd";
    int k = 2;
    cout << sol.longestIdealString(s, k) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-ideal-subsequence
