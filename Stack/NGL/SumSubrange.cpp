#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void printFunction(vector<int> &nums)
{
    for (int i : nums)
        cout << i << " ";
    cout << endl;
}

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        // range = sum of maximum of all subarrays - minimum
        // we can find sum of maximum of all subarrays;
        // by adding (element) * (no. of subarrays in which element is the maximum)
        // we can find that no. of subarrays by checking to left and right of element
        // for next greater and prev greater, as they will replace element as mini
        // no. of total subarrays will be size of subarr (left * right)
        // do same of mini sum, but subtract from answer

        // pre-calculate Next/Prev Greater/Smaller using monotonic stack
        vector<long long> nge(n, n), nse(n, n), pge(n, -1), pse(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (st.size() && nums[st.top()] < nums[i])
            {
                nge[st.top()] = i;
                st.pop();
            }
            if (st.size()) // this calc prev greater, also takes care of duplicate edge cases
                pge[i] = st.top();
            st.push(i);
        }

        while (st.size())
            st.pop();

        for (int i = 0; i < n; i++)
        {
            while (st.size() && nums[st.top()] > nums[i])
            {
                nse[st.top()] = i;
                st.pop();
            }
            if (st.size())
                pse[i] = st.top();
            st.push(i);
        }

        // first we need to calc no. of elements to left/right
        // as pre-calc arrays contain indices
        // just mini them with current i to find left/right subarr
        // we have initialized them smartly to avoid edge cases

        // multiply left * right to calc total no. of subarrays in which arr[i] is max/min
        // and multiply that with arr[i] to calc sum of max/min;
        // and add/sub to ans
        for (int i = 0; i < n; i++)
        {
            ans += nums[i] * ((nge[i] - i) * (i - pge[i])); // add maxi
            ans -= nums[i] * ((nse[i] - i) * (i - pse[i])); // subt mini
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.subArrayRanges(nums) << endl;
    return 0;
}

// https://leetcode.com/problems/sum-of-subarray-ranges/
