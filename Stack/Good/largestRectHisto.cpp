#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Official noob solution
class Solution2
{
    vector<int> prevSmallerElement(vector<int> &arr)
    {
        vector<int> ans;
        stack<int> stk;
        for (int i = 0; i < arr.size(); i++)
        {
            while (stk.size() && arr[stk.top()] >= arr[i])
                stk.pop();
            if (stk.empty())
                ans.push_back(-1);
            else
                ans.push_back(stk.top());
            stk.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &arr)
    {
        vector<int> ans;
        stack<int> stk;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (stk.size() && arr[stk.top()] >= arr[i])
                stk.pop();
            if (stk.empty())
                ans.push_back(arr.size());
            else
                ans.push_back(stk.top());
            stk.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> pse = prevSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int area = (nse[i] - pse[i] - 1) * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};

// My genius solution
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> st;
        // to avoid re-emptying stack after loop
        heights.push_back(0);
        for (int i : heights)
        {
            int count = 1;
            // keep popping & counting st as long as top > i
            while (st.size() && st.top() > i)
            {
                // stack will be decreasing
                // hence keep comparing maxheight * count = area
                ans = max(ans, st.top() * count++);
                st.pop();
            }
            // finally push minimum height of popped stack for future area
            while (count-- && i != 0)
                st.push(i);
        }
        return ans;
    }
};

int main()
{
    // vector<int> nums = {2, 1, 5, 6, 2, 3};
    // vector<int> nums = {2, 1, 5, 6, 2, 3, 11};
    vector<int> nums = {2, 1, 5, 6, 2, 3, 11, 2};

    Solution sol;
    cout << sol.largestRectangleArea(nums) << endl;

    Solution2 sol2;
    cout << sol2.largestRectangleArea(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/largest-rectangle-in-histogram/
