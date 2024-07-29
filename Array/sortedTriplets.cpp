#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int ans = 0;
        int n = rating.size();
        for (int i = 1; i < n - 1; i++)
        {
            int ls = 0, lg = 0, rs = 0, rg = 0;
            // left
            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[j] > rating[i])
                    lg++;
                else
                    ls++;
            }
            // right
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > rating[i])
                    rg++;
                else
                    rs++;
            }

            ans += ls * rg + lg * rs;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // vector<int> rating = {2, 5, 3, 4, 1};
    vector<int> rating = {1, 2, 3, 4};
    cout << sol.numTeams(rating) << endl;
    return 0;
}

// https://leetcode.com/problems/count-number-of-teams
