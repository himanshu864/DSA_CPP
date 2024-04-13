#include <iostream>
#include <vector>
using namespace std;

// Boyer Moore : Majority Vote Algorithm
int majorityElement(vector<int> &nums)
{
    int ans = 0, count = 0;
    for (int i : nums)
    {
        if (count == 0)
            ans = i;

        if (i == ans)
            count++;
        else
            count--;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
    return 0;
}

// https://leetcode.com/problems/majority-element/
