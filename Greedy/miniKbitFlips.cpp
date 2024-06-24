#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (q.size() % 2 == nums[i])
            {
                if (i + k - 1 >= n)
                    return -1;
                q.push(i + k - 1);
                ans++;
            }

            if (q.size() && q.front() == i)
                q.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    int k = 3;
    cout << sol.minKBitFlips(nums, k) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips