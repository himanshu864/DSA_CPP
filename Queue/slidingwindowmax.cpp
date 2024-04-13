#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> q; // need to pop back and front
        for (int i = 0; i < nums.size(); i++)
        {
            // push such that deque is in non-decreasing order
            // pop back until there is no one smaller in front
            while (q.size() && nums[i] > q.back())
                q.pop_back();
            q.push_back(nums[i]);

            // once i exceed window, pop out last element
            // will only pop front once if front == nums[i]
            // i.e. in case of leaving element == window max
            // else already popped out
            if (i >= k && q.front() == nums[i - k])
                q.pop_front();

            // once window is full
            // push current max == front to ans
            if (i + 1 >= k)
                ans.push_back(q.front());
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/sliding-window-maximum/
