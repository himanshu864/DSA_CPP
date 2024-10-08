#include <iostream>
#include <vector>
using namespace std;

// Recursive - Time Complexity: O(2^n), Space Complexity: O(n)
class Solution1
{
    int effort(vector<int> &height, int k, int x)
    {
        if (x == 0)
            return 0;
        int ans = INT_MAX;
        for (int i = 1; i <= k && x >= i; i++)
            ans = min(ans, effort(height, k, x - i) + abs(height[x] - height[x - i]));
        return ans;
    }

public:
    int minimizeCost(int k, vector<int> &arr)
    {
        return effort(arr, k, arr.size() - 1);
    }
};

// Memoization - Time Complexity: O(n * k), Space Complexity: O(n)
class Solution2
{
    int effort(vector<int> &height, vector<int> &dp, int k, int x)
    {
        if (dp[x] == -1)
        {
            int ans = INT_MAX;
            for (int i = 1; i <= k && x >= i; i++)
                ans = min(ans, effort(height, dp, k, x - i) + abs(height[x] - height[x - i]));
            dp[x] = ans;
        }
        return dp[x];
    }

public:
    int minimizeCost(int k, vector<int> &arr)
    {
        vector<int> dp(arr.size(), -1);
        dp[0] = 0;
        return effort(arr, dp, k, arr.size() - 1);
    }
};

// Tabulation - Time Complexity: O(n * k), Space Complexity: O(n)
class Solution3
{
public:
    int minimizeCost(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int effort = INT_MAX;
            for (int j = 1; j <= k && i >= j; j++)
                effort = min(effort, dp[i - j] + abs(arr[i] - arr[i - j]));
            dp[i] = effort;
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution3 sol;
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << sol.minimizeCost(k, arr) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/minimal-cost/1
