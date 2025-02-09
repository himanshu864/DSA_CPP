#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = INT_MIN;
        int maxi = 1, mini = 1; // curr max and min subarr product ending at i
        for (int num : nums)
        {
            int prev_min = mini, prev_max = maxi;
            mini = min({num, num * prev_min, num * prev_max});
            maxi = max({num, num * prev_min, num * prev_max});
            ans = max(ans, maxi);
        }
        return ans;
    }
};

int main()
{
    int n = 4;
    cout << n << '\n';
    return 0;
}

// https://leetcode.com/problems/maximum-product-subarray/
