#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        // elements with freq inside a hashmap
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;

        // convert hashmap into a vector<pair>> for sorting
        vector<pair<int, int>> temp(mp.begin(), mp.end());
        // sort decreasingly acc. to value(freq) using lambda fn
        sort(temp.begin(), temp.end(),
             [&](pair<int, int> &a, pair<int, int> &b)
             {
                 return a.second > b.second;
             });

        // push top k elements with max freq to ans
        for (int i = 0; i < k; i++)
            ans.push_back(temp[i].first);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 4, 5, 5};
    int k = 3;
    vector<int> ans = sol.topKFrequent(nums, k);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/top-k-frequent-elements/
