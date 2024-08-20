#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int length = piles.size();
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));
        vector<int> sufsum(length + 1, 0);
        for (int i = length - 1; i >= 0; i--)
            sufsum[i] = sufsum[i + 1] + piles[i];
        for (int i = 0; i <= length; i++)
            dp[i][length] = sufsum[i];
        for (int i = length - 1; i >= 0; i--)
            for (int j = length - 1; j >= 1; j--)
                for (int X = 1; X <= 2 * j && i + X <= length; X++)
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
        return dp[0][1];
    }
};

int main()
{
    Solution sol;
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << sol.stoneGameII(piles) << endl;
    return 0;
}

// https://leetcode.com/problems/stone-game-ii/
