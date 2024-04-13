#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSelectedElements(vector<int> &nums)
{
    int ans = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int maxi = 0;
        int start = nums[i];
        if (nums[i] + 2 == nums[i + 1])
            start = nums[i] + 1;
        for (int j = i; j < nums.size(); j++)
        {
            if ((nums[j] == start + j - i) || (nums[j] + 1 == start + j - i))
                maxi++;
            else
                break;
        }
        ans = max(ans, maxi);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 5, 1, 1};
    // vector<int> nums = {8, 10, 6, 12, 9, 12, 2, 3, 13, 19, 11, 18, 10, 16};
    cout << maxSelectedElements(nums) << endl;
    for (int i : nums)
        cout << i << " ";
    return 0;
}
