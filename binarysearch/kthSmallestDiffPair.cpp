#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
We want to find the kth Smallest abs Difference b/w any pair in array
That difference can be from 0 to (Maxi - Mini).
And we can binary search for answer using that range
For every Mid (= (L + R) / 2). Count how many pairs exist which sum Less than equal to Mid
Using sliding window on the sorted array. No need for n^2.
Find there are less pairs with diff. <= mid. Mid can't possibily be the answer. Hence L = mid + 1
Else if more pairs with diff <= mid. Mid can be the answer but no greater. Hence R = mid
Also if no. of pairs == k. Then also it's possible that mid is ans or smaller.
*/

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        // Sort the array to use the sliding window approach
        sort(nums.begin(), nums.end());

        // Binary search for the smallest distance
        int s = 0, e = nums.back() - nums.front();

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            int count = 0, i = 0;

            // Count pairs with a distance less than or equal to mid
            for (int j = 1; j < nums.size(); j++)
            {
                while (nums[j] - nums[i] > mid)
                    i++;
                count += j - i;
            }

            // Adjust binary search range based on count
            if (count < k)
                s = mid + 1;
            else
                e = mid;
        }

        // The smallest distance that meets the condition
        return s;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 1};
    int k = 1;
    cout << sol.smallestDistancePair(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/find-k-th-smallest-pair-distance
