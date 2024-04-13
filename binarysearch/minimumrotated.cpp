#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (nums[s] < nums[e])
            return nums[s];

        int mid = s + (e - s) / 2;
        int prev = (mid - 1 + n) % n;
        if (nums[mid] <= nums[prev])
            return nums[mid];
        else if (nums[s] <= nums[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return nums[s];
}

int main()
{
    vector<int> nums = {5, 6, 1, 2, 3, 4};
    cout << findMin(nums);
    return 0;
}
