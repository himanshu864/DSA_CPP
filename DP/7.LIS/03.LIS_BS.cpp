#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubsequence(int n, int a[])
    {
        int ans = 0;
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            // Binary Search to find the index just greater than equal to a[i]
            int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[j] = a[i];
            ans = max(ans, j);
        }
        return ans + 1;
    }
};

// This is what lower_bound is doing
/*
int s = 0, e = n - 1;
int j = 0;
while (s <= e)
{
    int mid = (s + e) / 2;
    if (dp[mid] >= a[i])
    {
        j = mid;
        e = mid - 1;
    }
    else
        s = mid + 1;
}
*/

int main()
{
    Solution sol;
    int a[] = {5, 8, 3, 7, 9, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << sol.longestSubsequence(n, a) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
