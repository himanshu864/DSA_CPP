#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int boratNOT(int n, int maximumBit)
    {
        int ans = 0, bit = 0;
        for (int i = n; i; i /= 2)
        {
            ans += (1 << bit) * (i % 2 == 0 ? 1 : 0);
            bit++;
        }
        while (bit < maximumBit)
        {
            ans += (1 << bit);
            bit++;
        }
        return ans;
    }

public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> ans;
        int temp = 0, maxi = (1 << maximumBit) - 1;
        for (int i : nums)
        {
            temp ^= i;
            ans.push_back(temp == 0 ? maxi : boratNOT(temp, maximumBit));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 1, 3};
    int maximumBit = 2;
    vector<int> ans = sol.getMaximumXor(nums, maximumBit);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-xor-for-each-query/
