#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> ans;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
                if (arr[i] < arr[j])
                    ans = max(ans, 1 + dp[j]);
            dp[i] = ans;
        }
        int maxi = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; i++)
            if (dp[i] == maxi)
            {
                ans.push_back(arr[i]);
                if (maxi-- == 1)
                    break;
            }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 0, 3, 2, 3};
    // vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> ans = sol.longestIncreasingSubsequence(arr.size(), arr);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
