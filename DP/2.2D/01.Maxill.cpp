#include <iostream>
#include <vector>
using namespace std;

/*
Most important and hardest thing is to make recurance relationship
To do that. Think recursively or rather dynamically

Here, f(day, last) = maximum points possible on that day if last was levelled up previously
We need to know was last levelled up skill in order to avoid that in current step
And if last = 3. Hence no levelling up previously. Go down all three subtrees

Dry run recursive tree:
- f(n, 3) => no skill was levelled up on n = 3rd day. Hence go wild.
- level up all skills one by one. answer can be arr[3 - 1][0] + f(2, 0) or last = 1 or 2
- for f(2, 0) => what are the max points possible on 2nd day having 0th skill levels up last
- hence, simply avoid levelling up 1st skill and you're good.
- And so on...
 */

// Note: Day is 1-indexed

// Recursive - O(3^n) & O(n)
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int day, int last = 3)
    {
        if (day == 0)
            return 0;
        int ans = 0;
        for (int i = 0; i < 3; i++)
            if (i != last)
                ans = max(ans, arr[day - 1][i] + maximumPoints(arr, day - 1, i));
        return ans;
    }
};

// Memoization - O(n) & O(n)
class Solution2
{
    // here we memoize maximum points on that day if last skills was levelled up
    // base case -> 0th day. dp[0] = {0,0,0} no matter last skill
    // Hence dp is grid of size [n + 1][4]. where n -> day and 4 -> last levelled up (0/1/2/none)
    int helper(vector<vector<int>> &arr, vector<vector<int>> &dp, int day, int last)
    {
        if (dp[day][last] == -1)
        {
            int ans = 0;
            for (int i = 0; i < 3; i++)
                if (i != last)
                    ans = max(ans, arr[day - 1][i] + helper(arr, dp, day - 1, i));
            dp[day][last] = ans;
        }
        return dp[day][last];
    }

public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        dp[0] = vector<int>(4, 0);
        return helper(arr, dp, n, 3);
    }
};

// Tabulation - O(n) & O(n)
class Solution3
{
    /*
    dp on nth day with last = 0. means max of (take 1st skill on nth day + max points on (n - 1) day with last = 1, ||ly last = 2)
    hence dp on nth day with last = 3. means max of (last = 0, 1, and 2)
    we can simply that max of dp[n][0] and dp[n][1] to calculate dp[n][4]. Since max(max(b,c),max(a,c)) = max(a,b,c)
    */
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        dp[0] = vector<int>(3, 0);
        for (int day = 1; day <= n; day++)
            for (int last = 0; last < 3; last++)
            {
                int ans = 0;
                for (int i = 0; i < 3; i++)
                    if (i != last)
                        ans = max(ans, arr[day - 1][i] + dp[day - 1][i]);
                dp[day][last] = ans;
            }
        return max(dp[n][0], dp[n][1]);
    }
};

// Space Optimization - O(n) & O(1)
class Solution4
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<int> prev = vector<int>(3, 0);
        for (int day = 1; day <= n; day++)
        {
            vector<int> curr(3, -1);
            for (int last = 0; last < 3; last++)
            {
                int ans = 0;
                for (int i = 0; i < 3; i++)
                    if (i != last)
                        ans = max(ans, arr[day - 1][i] + prev[i]);
                curr[last] = ans;
            }
            prev = curr;
        }
        return max(prev[0], prev[1]);
    }
};

int main()
{
    Solution3 sol;
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3},
    };
    cout << sol.maximumPoints(arr, arr.size()) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/geeks-training/1
