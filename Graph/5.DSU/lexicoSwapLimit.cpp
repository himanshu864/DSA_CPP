#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;                       // mp[value] -> family_no
        unordered_map<int, priority_queue<int>> families; // group and sort family members

        // group sorted nums based on swap-ability
        int family_no = 0;
        mp[sorted[0]] = family_no;
        families[family_no].push(-sorted[0]);
        for (int i = 1; i < n; i++)
        {
            if (abs(sorted[i] - sorted[i - 1]) > limit)
                family_no++;
            mp[sorted[i]] = family_no;
            families[family_no].push(-sorted[i]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            family_no = mp[nums[i]];             // find family number of nums[i]
            ans[i] = -families[family_no].top(); // insert smallest member of that family
            families[family_no].pop();           // remove that member
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {10, 5, 1, 20, 6};
    int limit = 5;
    vector<int> ans = sol.lexicographicallySmallestArray(nums, limit);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
