#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int ans = 0;
        int maxi = arrays[0].front();
        int mini = arrays[0].back();
        for (auto arr : arrays)
        {
            ans = max(ans, arr.back() - mini);
            ans = max(ans, maxi - arr.front());
            maxi = max(maxi, arr.back());
            mini = min(mini, arr.front());
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << sol.maxDistance(arrays) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-distance-in-arrays/
