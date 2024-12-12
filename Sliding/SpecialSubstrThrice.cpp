#include <iostream>
#include <vector>
using namespace std;

// God Mod - O(N)
class Solution
{
public:
    int maximumLength(string s)
    {
        int ans = -1;
        int n = s.size();
        // freq[i][j] maps frequency of special substr of char s[i] of j size
        // eg: freq[0][2] = 1 => aa
        vector<vector<int>> freq(26, vector<int>(n + 1, 0));

        // map freq of special substrings in a string iteration
        // note freq of overlapping substrings aren't accounted for yet
        // eg : aaaa, here a is only counted once, similarly aa, aaa, and aaaa
        // we will count prefix sum is reverse to remedy that
        // eg: freq[aaaa] = 1, freq[aaa] = 1 + freq[aaaa], freq[aa] = 2 + 1, ...
        // because aaaa contains two aaa's. And we have already counted the first aaa
        // similarly one aaa contains two aa's.
        // i don't fucking know bro. suck my dick.. read the solution cunt
        char pre = s[0];
        int len = 1;
        freq[s[0] - 'a'][1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (pre != s[i])
            {
                pre = s[i];
                len = 1;
            }
            else
                len++;
            freq[pre - 'a'][len] += 1;
        }

        for (int i = 0; i < 26; i++)
        {
            int preSum = 0;
            for (int j = n; j >= 1; j--)
            {
                preSum += freq[i][j];
                if (preSum >= 3)
                {
                    ans = max(ans, j);
                    break;
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
