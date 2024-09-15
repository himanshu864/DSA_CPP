#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int ans = 0;
        unordered_map<int, int> m{{0, -1}};
        for (int i = 0, cur = 0; i < s.size(); i++)
        {
            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
            if (!m.count(cur))
                m[cur] = i;
            ans = max(ans, i - m[cur]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "eleetminicoworoep";
    cout << sol.findTheLongestSubstring(s);
    return 0;
}

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
