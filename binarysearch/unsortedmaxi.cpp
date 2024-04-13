#include <bits/stdc++.h>
using namespace std;

// here there are multiple peak elements, return any one
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    // edge cases
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (nums[mid + 1] > nums[mid])
            s = mid + 1;
        else if (nums[mid - 1] > nums[mid])
            e = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    vector<int> nums = {2, 4, 3, 5, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}
