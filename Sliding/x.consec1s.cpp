#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int ans = 0;
    int i = 0, j = 0;
    int zerocount = 0;
    while (j < nums.size())
    {
        if (nums[j] == 0)
            zerocount++;
        if (zerocount > k)
        {
            if (nums[i] == 0)
                zerocount--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 1, 0, 0, 1, 0};
    int k = 3;
    cout << longestOnes(nums, k);
    return 0;
}
// https://www.codingninjas.com/studio/problems/traffic_6682625
