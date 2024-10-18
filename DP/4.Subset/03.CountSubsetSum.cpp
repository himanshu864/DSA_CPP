#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int mod = 1e9 + 7;

// Recursion - O(2^n) & O(n)
class Solution1
{
public:
    // how many subsets from arr[0 -> i] with sum === sum
    // smaller step is pick or not pick
    // base case is sum should be 0 for empty array
    int perfectSum(int arr[], int n, int sum)
    {
        if (n == 0)
            return sum == 0;
        long pick = sum >= arr[n - 1] ? perfectSum(arr, n - 1, sum - arr[n - 1]) : 0;
        long notpick = perfectSum(arr, n - 1, sum);
        return (pick + notpick) % mod;
    }
};

// Memoization - O(n * sum) & O(n * sum)
class Solution2
{
    int helper(int arr[], vector<vector<int>> &dp, int i, int sum)
    {
        if (i < 0)
            return sum == 0;
        if (dp[i][sum] == -1)
        {
            long pick = sum >= arr[i] ? helper(arr, dp, i - 1, sum - arr[i]) : 0;
            long notpick = helper(arr, dp, i - 1, sum);
            dp[i][sum] = (pick + notpick) % mod;
        }
        return dp[i][sum];
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(arr, dp, n - 1, sum);
    }
};

// Smart Tabulation - O(n * sum) & O(n * sum)
class Solution3
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        // 1-indexed for base case
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        dp[0][0] = 1; // empty subset has sum = 0
        for (int i = 1; i <= n; i++)
            for (int s = 0; s <= sum; s++)
            {
                // if we picked up arr[i] element for s == sum
                // then add no. of subsets from arr[0 -> i - 1] with sum == s - arr[i]
                if (s >= arr[i - 1])
                    dp[i][s] = dp[i - 1][s - arr[i - 1]];

                // not pick; add with mod
                dp[i][s] = (dp[i][s] + dp[i - 1][s]) % mod;
            }
        return dp[n][sum];
    }
};

// Space Optimization - O(n * sum) & O(sum)
class Solution4
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<int> prev(sum + 1);
        prev[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr = prev; // not pick included
            for (int s = 0; s <= sum; s++)
                if (s >= arr[i - 1])
                    curr[s] = (curr[s] + prev[s - arr[i - 1]]) % mod;
            prev = curr;
        }
        return prev[sum];
    }
};

int main()
{
    Solution4 sol;
    int arr[] = {5, 2, 3, 10, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << sol.perfectSum(arr, n, sum) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
