#include <iostream>
#include <vector>
using namespace std;

int operations(vector<int> &nums, int i, int j, int sum)
{
    int ans = 1;
    while (j > i)
    {
        if (nums[i] + nums[i + 1] == sum)
            i += 2;
        else if (nums[j] + nums[j - 1] == sum)
            j -= 2;
        else if (nums[i] + nums[j] == sum)
            i++, j--;
        else
            break;
        ans++;
    }
    return ans;
}

int maxOperations(vector<int> &nums)
{
    int n = nums.size();
    int s = operations(nums, 2, n - 1, nums[0] + nums[1]);
    int e = operations(nums, 0, n - 3, nums[n - 1] + nums[n - 2]);
    int mid = operations(nums, 1, n - 2, nums[0] + nums[n - 1]);
    if (s >= e && s >= mid)
        return s;
    else if (e >= s && e >= mid)
        return e;
    return mid;
}

int main()
{
    // vector<int> nums = {3, 2, 1, 2, 3, 4};
    vector<int> nums = {2, 1, 6, 3, 4, 2, 4, 5};
    cout << maxOperations(nums) << endl;
    return 0;
}

/*

void operations(vector<int> &nums, int i, int j, int sum, int maxi, int &ans)
{
    if (j <= i)
    {
        ans = max(ans, maxi);
        return;
    }
    if (nums[i] + nums[i + 1] == sum)
        operations(nums, i + 2, j, sum, maxi + 1, ans);
    if (nums[j] + nums[j - 1] == sum)
        operations(nums, i, j - 2, sum, maxi + 1, ans);
    if (nums[i] + nums[j] == sum)
        operations(nums, i + 1, j - 1, sum, maxi + 1, ans);
}

int maxOperations(vector<int> &nums)
{
    int ans = 1;
    int n = nums.size();
    operations(nums, 2, n - 1, nums[0] + nums[1], 1, ans);
    operations(nums, 0, n - 3, nums[n - 1] + nums[n - 2], 1, ans);
    operations(nums, 1, n - 2, nums[0] + nums[n - 1], 1, ans);
    return ans;
}

*/