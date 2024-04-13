#include <iostream>
using namespace std;

class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        string ans(s.size(), 'a');

        int x = 0;
        for (int i = 0; i < s.size(); i++)
            x += min(s[i] - 97, 123 - s[i]);

        for (int i = s.size() - 1; i >= 0 && x > k; i--)
        {
            int temp = min(s[i] - 97, 123 - s[i]);
            ans[i] = s[i];
            if (x - temp < k)
                ans[i] -= (k - x + temp);
            x -= temp;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "xaxcd";
    int k = 4;
    cout << sol.getSmallestString(s, k) << endl;
    return 0;
}

// https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/
