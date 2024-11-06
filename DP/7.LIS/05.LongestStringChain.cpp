#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution1
{
    bool isPredecessor(string a, string b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0;
        for (char c : b)
            if (a[i] == c)
                i++;
        return i == a.size();
    }

    int f(int i, int prevIdx, vector<string> &words)
    {
        if (i == words.size())
            return 0;
        int notpick = f(i + 1, prevIdx, words);
        int pick = 0;
        if (prevIdx == -1 || isPredecessor(words[prevIdx], words[i]))
            pick = 1 + f(i + 1, i, words);
        return max(pick, notpick);
    }

public:
    int longestStrChain(vector<string> &words)
    {
        // sort strings by length. Not lexographically
        sort(words.begin(), words.end(), [&](string a, string b)
             { return a.size() < b.size(); });
        return f(0, -1, words);
    }
};

// Space Optimized Tabulation
class Solution2
{
    bool isPredecessor(string a, string b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0;
        for (char c : b)
            if (a[i] == c)
                i++;
        return i == a.size();
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string a, string b)
             { return a.size() < b.size(); });

        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--)
            for (int prev = -1; prev < i; prev++)
                if (prev == -1 || isPredecessor(words[prev], words[i]))
                    dp[prev + 1] = max(dp[prev + 1], 1 + dp[i + 1]);
        return dp[0];
    }
};

// LIS
class Solution
{
    bool isPredecessor(string a, string b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0;
        for (char c : b)
            if (a[i] == c)
                i++;
        return i == a.size();
    }

public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [&](string a, string b)
             { return a.size() < b.size(); });

        int n = words.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
                if (isPredecessor(words[i], words[j]))
                    ans = max(ans, 1 + dp[j]);
            dp[i] = ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << sol.longestStrChain(words) << endl;
    return 0;
}

// https://leetcode.com/problems/longest-string-chain/description/
