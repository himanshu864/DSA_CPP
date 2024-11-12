#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<int> bits;

    int bittudesimaal()
    {
        int desimaal = 0;
        for (int i = 31; i >= 0; i--)
            desimaal += (1 << (31 - i)) * (bits[i] > 0);
        return desimaal;
    }

    void OrWhat(int n, bool add)
    {
        for (int bit = 31; n; bit--, n /= 2)
            bits[bit] += (n % 2) * (add ? 1 : -1);
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int ans = INT_MAX;
        bits.resize(32);
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            OrWhat(nums[j], true);

            while (i <= j && bittudesimaal() >= k)
            {
                ans = min(ans, j - i + 1);
                OrWhat(nums[i++], false);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 8, 4, 1};
    int k = 10;
    cout << sol.minimumSubarrayLength(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
