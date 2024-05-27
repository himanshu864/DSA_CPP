#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 'x' keeps track of the potential special number, which is the count of numbers greater than or equal to 'x'.
    // We sort the array in descending order to easily check how many elements are greater than or equal to any given value.
    // We iterate through the sorted array, incrementing 'x' as long as the current element is greater than or equal to 'x'.
    // The loop breaks when we find an element that is smaller than the current value of 'x'.
    // After the loop, we check if the last value (stored in 'prev') is greater than or equal to 'x'.
    // This final check confirms that there will be exactly 'x' elements that are greater than or equal to 'x'.
    // For example, given nums = {1, 5, 3}:
    // - After sorting: {5, 3, 1}
    // - During the loop: 'x' increments until 'x' equals 2, because 3 (the second element) is greater than or equal to 2.
    // - The loop stops at 1 because 1 is less than 'x' (which is 2).
    // - We check if 'prev' (which is 3) is greater than or equal to 'x' (which is 2). Since it is, we return 'x' as the special value.
    // This confirms that there are exactly 2 elements (5 and 3) that are greater than or equal to 2.

    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int x = 0, prev = 10000;
        for (int i : nums)
        {
            if (i >= x)
            {
                prev = i;
                x++;
            }
            else
                break;
        }
        return (x <= prev) ? x : -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 5};
    cout << sol.specialArray(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
