#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        long long ans = 0;
        unordered_map<int, int> mp;
        // add all factorial's of num1 without repetition
        for (int num : nums1)
        {
            for (int i = 1; i * i <= num; i++)
            {
                if (i * i == num)
                {
                    mp[i]++;
                }
                else if (num % i == 0)
                {
                    mp[i]++;
                    mp[num / i]++;
                }
            }
        }
        // if nums2 * k divides nums1, it will exist as a factor
        for (int num : nums2)
            ans += mp[num * k];
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 4, 12};
    vector<int> nums2 = {2, 4};
    int k = 3;
    cout << sol.numberOfPairs(nums1, nums2, k) << endl;
    return 0;
}
