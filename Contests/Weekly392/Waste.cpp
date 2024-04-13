#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = n / 2;

        if (n % 2 == 0) // even
        {
            int curr = (nums[i] + nums[i - 1]); // current double of median
            ans += abs(curr - 2 * k);

            if (curr > 2 * k)
            {
                if (n == 2)
                    return ans;
                else
                {
                    int left = nums[i - 2];
                    if (left >= k)
                        left = k;
                    else
                    {
                        int smallestleft = nums[i - 1] - ans;
                        left = max(left, smallestleft);
                    }
                    for (int j = i - 2; j >= 0; j--)
                    {
                        if (nums[j] > left)
                            ans += (nums[j] - left);
                        else
                            break;
                    }
                }
            }
            else if (curr < 2 * k)
            {
                if (n == 2)
                    return ans;
                else
                {
                    int right = nums[i + 1];
                    if (right <= k)
                        right = k;
                    else
                    {
                        int largestright = nums[i] + ans;
                        right = min(right, largestright);
                    }
                    for (int j = i + 1; j < n; j++)
                    {
                        if (nums[j] < right)
                            ans += (right - nums[j]);
                        else
                            break;
                    }
                }
            }
        }
        else // odd
        {
            if (k > nums[i])
            {
                ans += (k - nums[i]);
                for (int j = i + 1; j < n; j++)
                {
                    if (k > nums[j])
                        ans += (k - nums[j]);
                    else
                        break;
                }
            }
            else if (k < nums[i])
            {
                ans += (nums[i] - k);
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] > k)
                        ans += (nums[j] - k);
                    else
                        break;
                }
            }
            else
                return 0;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 4, 5, 5, 6, 7};
    int k = 3;
    cout << sol.minOperationsToMakeMedianK(nums, k) << endl;
    return 0;
}
