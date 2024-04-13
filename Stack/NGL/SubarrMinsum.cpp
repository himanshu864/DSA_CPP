#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute force is O(n^2)
// Observe: In case of 3 1 2 4. There will be 10 total subarrays
// 3, 3 1, 3 1 2, 3 1 2 4
// 1, 1 2, 1 2 4
// 2, 2 4
// 4
// and minimum sum will come from:
// (3 x 1) + (1 x 6) + (2 x 2) + (4 x 1) == 17
// Therefore, we just need to calculate no. of subarrays arr[i] in the minimum of
// and we can ans += (arr[i] * number) for total minimum sum

// For calc. of number of subarrays arr[i] is the minimum of
// We need to find a smaller element to the left and to the right
// as after that element enters subarray, arr[i] will be replaced
// we can calc. number of subarrays in that range by multiplying elements to left by elements to right
// For example : 3 1 2 4 0 : To find no. of sub with mini [1]
// There are total 2 elements to left of 1, that are greater (including 1 for subarray multiplication)
// and a total of 3 to the right.
// Any range after that, would have 1 as minimum
// Hence sub[1] = 2 * 3 = 6
// As subarrays [3 1] and [1 2 4] create a total of 6 arrays combined

// We can create nextsmaller and prev smaller to store similar indices for each element
// and calc total by using above formula

// This is a monotonic stack solution as all elements greater then arr[i] get's popped out

class Solution
{
    vector<int> nextSmaller(vector<int> &arr) // indices
    {
        vector<int> ans(arr.size(), arr.size()); // initialize with n, for right, if doesn't exist
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (st.size() && arr[st.top()] >= arr[i]) // V.V.IMP to handle duplicate elements edge!!
            {
                ans[st.top()] = i; // update next[popping index] = smaller index
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &arr)
    {
        vector<int> ans(arr.size(), -1); // init with -1 for left, if doesn't exist
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) // start from back for prev popping
        {
            while (st.size() && arr[st.top()] > arr[i]) // anyone side will do
            {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

public:
    int mod = 1e9 + 7; // important for bs modulo
    int sumSubarrayMins(vector<int> &arr)
    {
        long long ans = 0;
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevSmaller(arr);

        // Concise version : for next and prev
        // stack<int> st;
        // vector<int> prev(arr.size(), -1), next(arr.size(), arr.size());

        // for (int i = 0; i < arr.size(); ++i)
        // {
        //     while (!st.empty() && arr[st.top()] > arr[i])
        //     {
        //         next[st.top()] = i;
        //         st.pop();
        //     }
        //     if (!st.empty()) // as stack in increasing order, prev element must be smaller
        //         prev[i] = st.top();
        //     st.push(i);
        // }

        for (int i = 0; i < arr.size(); i++)
        {
            long long ne = (next[i] - i) % mod;       // to calc total no. of elements to the right
            long long pe = (i - prev[i]) % mod;       // and left greater then arr[i]
            long long sum = (arr[i] * ne * pe) % mod; // total no. of subarrays with arr[i] as minimum
            ans = (ans + sum) % mod;                  // add all minimums to answer
        }
        return int(ans);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << sol.sumSubarrayMins(arr) << endl;
    return 0;
}

// https://leetcode.com/problems/sum-of-subarray-minimums/
