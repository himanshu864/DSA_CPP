#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    vector<string> ans;
    string output;

    void helper(string &s, vector<string> &wordDict, int i)
    {
        if (i == s.size())
        {
            ans.push_back(output);
            return;
        }

        for (string word : wordDict)
        {
            if (s.substr(i, word.size()) == word)
            {
                output = output.empty() ? word : output + " " + word;

                helper(s, wordDict, i + word.size());

                output = output.substr(0, output.size() - word.size());
                if (output.size())
                    output.pop_back();
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        helper(s, wordDict, 0);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> ans = sol.wordBreak(s, wordDict);

    for (string x : ans)
        cout << x << endl;
    return 0;
}

// https://leetcode.com/problems/word-break-ii/
