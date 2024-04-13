#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool helper(string &s, vector<string> &wordDict, vector<bool> &nope, int i)
    {
        if (i == s.size())
            return true;
        if (nope[i])
            return false;

        for (string x : wordDict)
            if (s.substr(i, x.size()) == x &&
                helper(s, wordDict, nope, i + x.size()))
                return true;

        nope[i] = true;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> nope(s.size(), false);
        return helper(s, wordDict, nope, 0);
    }
};

int main()
{
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "neetcode", "code"};
    cout << sol.wordBreak(s, wordDict) << endl;
    return 0;
}

// https://leetcode.com/problems/word-break/
