#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        // map element to their smallest index
        vector<int> mp(100001, -1);
        for (int i = (int)elements.size() - 1; i >= 0; i--)
            mp[elements[i]] = i;

        // for each group, find divisor with smallest index
        vector<int> ans;
        for (int g : groups)
        {
            int mind = 1e6;
            for (int i = 1; i * i <= g; i++)
                if (g % i == 0)
                {
                    if (mp[i] != -1)
                        mind = min(mind, mp[i]);
                    if (mp[g / i] != -1)
                        mind = min(mind, mp[g / i]);
                }
            ans.push_back(mind != 1e6 ? mind : -1);
        }
        return ans;
    }
};
;

int main()
{
    Solution sol;
    vector<int> groups = {8, 4, 3, 2, 4};
    vector<int> elements = {4, 2};
    vector<int> ans = sol.assignElements(groups, elements);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/assign-elements-to-groups-with-constraints/
