#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Approach: Use sliding Window and Hashmap to track if all chars of words 2 are in window
// use int count to keep track of required chars. Initially word2.size()
// once count == 0. All substrings from i to (j, j + 1, j + 2, ... , n - 1) will satisfy
// Hence ans += (n - j) and move left pointer

// Also, only increase count(req char) if we remove a req character
// And decrease count if add we add a req char

class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        long long ans = 0;
        int n = word1.size();
        vector<int> req(26, 0);
        int count = word2.size();

        for (char c : word2)
            req[c - 'a']++;

        int i = 0, j = 0;
        while (j < n)
        {
            if (--req[word1[j] - 'a'] >= 0)
                count--;

            while (count == 0)
            {
                ans += (n - j);
                if (++req[word1[i] - 'a'] > 0)
                    count++;
                i++;
            }
            j++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string word1 = "dcbdcdccb";
    string word2 = "cdd";
    cout << sol.validSubstringCount(word1, word2) << endl;
    return 0;
}

// https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii/
