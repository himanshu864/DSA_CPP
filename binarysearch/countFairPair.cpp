#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            // BS the smallest index with sum >= lower
            int s = i + 1;
            int e = n - 1;
            int x = i;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (nums[i] + nums[mid] >= lower)
                {
                    x = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }

            // now BS the greatest index with sum <= upper
            s = i + 1;
            e = n - 1;
            int y = i;
            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (nums[i] + nums[mid] <= upper)
                {
                    y = mid;
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }

            // From index i, we can make (y - x + 1) fair pairs
            if (x != i && y != i)
                ans += (y - x + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    cout << sol.countFairPairs(nums, lower, upper) << endl;
    return 0;
}

// https://leetcode.com/problems/count-the-number-of-fair-pairs/
