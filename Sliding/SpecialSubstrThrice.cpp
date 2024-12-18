#include <iostream>
#include <vector>
using namespace std;

// God Mod - O(N)
class Solution
{
public:
    int maximumLength(string s)
    {
        int n = s.size();
        // freq[i][j] maps frequency of special substr of char s[i] of j size
        // Note: for string "aaaa", we only count "a", "aa", "aaa", "aaaa" only once
        // And calc. actual freq by adding suffix.
        // Eg: freq[aaaa] = 1; [aaa] = 1 + 1; [aa] = 1 + 2; [a] = 1 + 3;
        vector<vector<int>> freq(26, vector<int>(n + 1));
        freq[s[0] - 'a'][1] = 1;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;
            freq[s[i] - 'a'][count] += 1;
        }

        int ans = 0;
        // for each character, find longest special with freq >= 3
        for (int i = 0; i < 26; i++)
        {
            int count = 0;
            for (int j = n; j > 0; j--)
            {
                count += freq[i][j];
                if (count >= 3)
                {
                    ans = max(ans, j);
                    continue;
                }
            }
        }
        return ans;
    }
};

/*
// easy binary search O(NlogN)
class Solution:
    # sliding window to check if a special substr of size mid
    # occurs at least 3 times
    def __specialExists(self, s: str, mid: int) -> bool:
        count = [0] * 26
        i, j = 0, 0
        n = len(s)
        while j < n:
            while j < n and s[i] == s[j]:
                j += 1

            if j - i >= mid:
                x = ord(s[i]) - 97
                count[x] += (j - i - mid + 1)
                if count[x] >= 3:
                    return True

            i = j
        return False

    # binary search to find maximum possible size of valid substring
    def maximumLength(self, s: str) -> int:
        ans = -1
        l = 1
        h = len(s)
        while(l <= h):
            mid = l + ((h - l) >> 1)
            if self.__specialExists(s, mid):
                ans = mid
                l = mid + 1
            else:
                h = mid - 1
        return ans

*/

int main()
{
    Solution sol;
    string s = "aaaa";
    // string s = "abcaba";
    cout << sol.maximumLength(s) << endl;
    return 0;
}

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/
