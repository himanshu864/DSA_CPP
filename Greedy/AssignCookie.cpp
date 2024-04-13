#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// first we have to skip all cookies smaller then least greedy children demand
// Hence, iterate through size and start assigning when size >= greed
// ans will also keep track of children index, and want to stop if more cookies then children's demand

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for (int i : s)
        {
            if (i >= g[ans])
                ans++;
            if (ans == g.size())
                break;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> greed_children = {1, 2, 3};
    vector<int> size_cookie = {2, 2};
    cout << sol.findContentChildren(greed_children, size_cookie) << endl;
    return 0;
}

// https://leetcode.com/problems/assign-cookies/
