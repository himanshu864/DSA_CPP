#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
    // Since, negative values, sliding window won't work.
    // Because increasing left pointer doesn't ensure subarr sum will decrease
    // To find the smallest subarray with sum >= k
    // We keep to find the longest prefix with smallest sum, for all indices
    // And we'll use a minHeap for that. Remove and update ans while curr_prefix - top.first >= k
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        long long ans = INT_MAX;
        long long prefix = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minHeap;
        minHeap.push({0, -1}); // prefix, index: want to minimize prefix and maximize index
        for (int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            while (minHeap.size() && prefix - minHeap.top().first >= k)
            {
                ans = min(ans, i - minHeap.top().second);
                minHeap.pop();
                // we can remove this prefix from minHeap,
                // because even if we find another index with sum - prefix >= k,
                // it won't be the shortest
            }
            minHeap.push({prefix, i});
        }
        return ans != INT_MAX ? ans : -1;
    }
};

int main()
{
    Solution sol;
    // vector<int> nums = {-1, 2, -2, 2, -1, 2, 1};
    // int k = 3;
    vector<int> nums = {-34, 37, 51, 3, -12, -50, 51, 100};
    int k = 151;
    cout << sol.shortestSubarray(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
