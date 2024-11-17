#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    // let's first tabulate sums of all possible subsets
    vector<int> dp(10001);
    dp[arr[0]] = true;
    for (int i = 1; i < n; i++)
        for (int sum = 10000; sum >= 0; sum--)
            if (sum >= arr[i])
                dp[sum] = dp[sum] || dp[sum - arr[i]];

    // now we can calculate abs diff of all possible sums by abs((sum) - (totalSum - sum))
    int ans = INT_MAX;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    for (int sum = 0; sum <= 10000; sum++)
        if (dp[sum])
            ans = min(ans, abs(2 * sum - totalSum));
    return ans;
}

int main()
{
    vector<int> arr = {3, 9, 7, 3};
    cout << minSubsetSumDifference(arr, arr.size()) << endl;
    return 0;
}

// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
