#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (mid % 2 == 1)
            mid--;
        if (nums[mid] == nums[mid + 1])
            s = mid + 2;
        else
            e = mid;
    }
    return nums[s];
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    cout << singleNonDuplicate(nums);
    return 0;
}