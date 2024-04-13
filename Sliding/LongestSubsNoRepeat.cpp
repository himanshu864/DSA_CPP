#include <iostream>
#include <vector>
using namespace std;

// Iterate through the string and keep a hashmap of character with it's index
// Sliding Window Approach : keep a left pointer i to keep track of start of the substring
// If current s[j] character has already appeared in the hashmap and it's appearance index is after left pointer i
// Only then we must update left pointer to index just after that appearance
// which makes sure substring window does have any repeating character and is also the longest

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        vector<int> charIdx(128, -1);
        for (int i = 0, j = 0; j < s.size(); j++)
        {
            if (charIdx[s[j]] >= i)
                i = charIdx[s[j]] + 1;

            charIdx[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "pwwekw";
    // string s = "vbxpvwkkteaiob";
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
