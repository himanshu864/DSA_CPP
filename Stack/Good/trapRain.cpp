#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Best official : Constant Space sliding window : O(N) and O(1)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() < 3)
            return 0;
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int leftmax = height[l], rightmax = height[r];
        // Water will fill b/w two long bars, let leftmax and rightmax
        // we l++ and r-- and calc water trapped on each bar as we slide
        while (l < r)
        {
            // If rightmax becomes smaller, we need to calc water trapped on (r - 1)th bar
            // since leftmax is longer, water level will become rightmax and anything in b/w won't matter
            // eg : 4 ...... 1 3. Here, rightmax is 3, leftmax could be 100 > 3 doesn't matter, 1 will trap (3 - 1 == 2) water
            // But if (r - 1)th bar is longer, no water will trapped. update rightmax
            if (leftmax > rightmax)
            {
                rightmax = max(rightmax, height[--r]);
                ans += rightmax - height[r]; // since rightmax updated first, negative value not possible
            }
            // similarly when leftmax becomes smaller or equal, it becomes new water elevation threshold and (l + 1)th bar calc
            else
            {
                leftmax = max(leftmax, height[++l]);
                ans += leftmax - height[l];
            }
        }
        return ans;
    }
};

// I don't understand : Stack O(N) O(N)
class Solution3
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty() || height.size() < 2)
            return 0;
        stack<int> stack;
        int water = 0, i = 0;
        while (i < height.size())
        {
            if (stack.empty() || height[i] <= height[stack.top()])
                stack.push(i++);
            else
            {
                int pre = stack.top();
                stack.pop();
                if (!stack.empty())
                {
                    // find the smaller height between the two sides
                    int minHeight = min(height[stack.top()], height[i]);
                    // calculate the area
                    water += (minHeight - height[pre]) * (i - stack.top() - 1);
                }
            }
        }
        return water;
    }
};

// Vector O(N) O(N)
class Solution4
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> L(n), R(n);
        for (int i = 1; i < n; ++i)
            L[i] = max(height[i - 1], L[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            R[i] = max(height[i + 1], R[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (min(L[i], R[i]) >= height[i])
                ans += min(L[i], R[i]) - height[i];
        return ans;
    }
};

// My approach using stack O(N) O(N)
class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        stack<int> st;
        int bottom = 0; // current maximum will be at bottom, as stack decreasing
        // Notice water will trap b/w 2 long bars
        // Therefore, we store left max and stack until right max
        // and calculate water trapped while popping, as we know both now
        for (int i : height)
        {
            while (st.size() && i >= bottom) // pop when i >= maximum
            {
                ans += (min(bottom, i) - st.top()); // VIMP: how much water will fill
                st.pop();
            }
            if (st.empty())
                bottom = i;
            st.push(i);
        }
        // Now bottom is the longest bar, everything after that will be smaller
        // Hence, anything from right max to longest(bottom) will trap water
        // While, water will flow to the right of rightmax
        int maxi = 0;
        while (st.size())
        {
            if (st.top() >= maxi)
                maxi = st.top();
            else
                ans += maxi - st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(v);
    return 0;
}

// https://leetcode.com/problems/trapping-rain-water/
