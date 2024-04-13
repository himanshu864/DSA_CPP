#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int>
    nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i : nums2)
        {
            while (st.size() && st.top() < i)
            {
                mp[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (int i : nums1)
        {
            if (mp.count(i))
                ans.push_back(mp[i]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/next-greater-element-i/
