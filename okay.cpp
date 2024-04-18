#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for each sliding window, shrink until all elements inside window can be increased upto righest ideal element
// as operations can't decrease.
// if ideal sum = ideal * number of elements minus(-) current sum > k
// shrink i++

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long long ans = 0, sum = 0;
        for (long long i = 0, j = 0; j < nums.size(); j++)
        {
            long long ideal = nums[j];
            sum += ideal;
            while ((j - i + 1) * ideal - sum > k)
                sum -= nums[i++];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 5, 8, 13};
    int k = 5;
    cout << sol.maxFrequency(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
