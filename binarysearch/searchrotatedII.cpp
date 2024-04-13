#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (nums[mid] == target)
            return true;

        else if ((nums[s] == nums[mid]) && (nums[mid] == nums[e]))
        {
            s++;
            e--;
        }
        else if (nums[s] <= nums[mid])
        {
            if (nums[s] <= target && target < nums[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {5, 6, 1, 1, 2, 3, 4, 5};
    int target = 2;
    cout << search(nums, target) << endl;
    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
