#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Just put entire word sequences into queue and proceed same as Word-ladder-I
// Memory Limit Exceeded!
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return ans;

        bool lastLevel = false;
        queue<vector<string>> q;
        q.push({beginWord});
        while (q.size())
        {
            for (int n = q.size(); n; n--)
            {
                vector<string> sequence = q.front();
                string word = sequence.back();
                q.pop();
                if (word == endWord)
                {
                    ans.push_back(sequence);
                    lastLevel = true;
                    continue;
                }

                dict.erase(word);
                for (int i = 0; i < word.size(); i++)
                {
                    char o = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (dict.find(word) != dict.end())
                        {
                            sequence.push_back(word);
                            q.push(sequence);
                            sequence.pop_back();
                        }
                    }
                    word[i] = o;
                }
            }
            if (lastLevel)
                break;
        }
        return ans;
    }
};

// Striver Efficient Solution
class Solution
{
    unordered_map<int, unordered_set<string>> map;
    // Word Ladder - I
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while (q.size())
        {
            for (int n = q.size(); n; n--)
            {
                string word = q.front();
                q.pop();
                map[ladder].insert(word);

                if (word == endWord)
                    return ladder;

                for (int j = 0; j < word.size(); j++)
                {
                    char o = word[j];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;
                        if (dict.find(word) != dict.end())
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = o;
                }
            }
            ladder++;
        }
        return 0;
    }

    vector<vector<string>> ans;
    vector<string> output;
    // Word Ladder II
    void helper(int level)
    {
        if (level == 0)
        {
            reverse(output.begin(), output.end());
            ans.push_back(output);
            reverse(output.begin(), output.end());
            return;
        }

        // search similar in current level
        string word = output.back();
        for (string s : map[level])
        {
            // compare word and s
            int count = 0;
            for (int i = 0; i < s.size(); i++)
                if (word[i] != s[i])
                    count++;

            // if only one difference. Call dfs
            if (count == 1)
            {
                output.push_back(s);
                helper(level - 1);
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // calc ladder Length and also map words per level
        int ladder = ladderLength(beginWord, endWord, wordList);
        if (ladder == 0)
            return ans;

        // Start DFS from endWord and backtrack to level 1 with beginWord
        output.push_back(endWord);
        helper(ladder - 1);
        return ans;
    }
};

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> ans = sol.findLadders(beginWord, endWord, wordList);
    for (vector<string> x : ans)
    {
        for (string s : x)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/word-ladder-ii/
