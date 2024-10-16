#include <iostream>
#include <vector>
using namespace std;

// Recursive
class Solution1
{
    // f(i, sum) checks if there exists a subset from 0 -> i with total = sum
    bool helper(vector<int> &arr, int i, int sum)
    {
        if (sum < 0)
            return false;
        if (sum == 0)
            return true;
        if (i == 0)
            return arr[i] == sum;
        return helper(arr, i - 1, sum) || helper(arr, i - 1, sum - arr[i]);
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        return helper(arr, arr.size() - 1, sum);
    }
};

// Memoization - O(n * sum) & O(n * sum)
class Solution2
{
    // f(i, sum) checks if there exists a subset from 0 -> i with total = sum
    bool helper(vector<int> &arr, vector<vector<int>> &dp, int i, int sum)
    {
        if (sum < 0)
            return false;
        if (dp[i][sum] == -1)
        {
            if (sum == 0)
                dp[i][sum] = true;
            else if (i == 0)
                dp[0][sum] = arr[0] == sum;
            else
                dp[i][sum] = helper(arr, dp, i - 1, sum) || helper(arr, dp, i - 1, sum - arr[i]);
        }
        return dp[i][sum];
    }

public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return helper(arr, dp, arr.size() - 1, sum);
    }
};

// Tabulation - O(n * sum) && O(n * sum)
class Solution3
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++)
            for (int s = 1; s <= sum; s++)
            {
                bool notpick = dp[i - 1][s], pick = false;
                if (s >= arr[i])
                    pick = dp[i - 1][s - arr[i]];
                dp[i][s] = pick || notpick;
            }
        return dp[n - 1][sum];
    }
};

// Space Optimization - O(n * sum) && O(sum)
class Solution4
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[arr[0]] = true;

        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(sum + 1, false);
            prev[0] = true;
            for (int s = 1; s <= sum; s++)
            {
                bool notpick = prev[s];
                bool pick = false;
                if (s >= arr[i])
                    pick = prev[s - arr[i]];
                curr[s] = pick || notpick;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

int main()
{
    Solution4 sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    // int sum = 30;
    cout << sol.isSubsetSum(arr, sum) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
