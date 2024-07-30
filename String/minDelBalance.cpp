#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int ans = INT_MAX;
        int ra = 0;
        for (auto c : s)
            if (c == 'a')
                ra++;

        if (s[0] == 'a')
            ra--;

        int lb = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans = min(ans, lb + ra);
            if (i + 1 < s.size() && s[i + 1] == 'a')
                ra--;
            if (s[i] == 'b')
                lb++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aababbab";
    // string s = "a";
    cout << sol.minimumDeletions(s) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced
