#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// just traverse twice for circular array, use % for indexing
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int N = nums.size();
        vector<int> ans(N, -1);
        stack<int> s;
        for (int i = 2 * N - 1; i >= 0; i--)
        {
            while (s.size() && s.top() <= nums[i % N])
                s.pop();
            if (s.size())
                ans[i % N] = s.top();
            s.push(nums[i % N]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> ans = sol.nextGreaterElements(nums);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/next-greater-element-ii/
