#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// First try - 20th August 2024 - 6:11 PM - Graph is easy

// Simple Concise Solution
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // create a dictionary which also works as visited
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
                if (word == endWord)
                    return ladder;

                // Now insert similar patterns into queue
                // To find that, compare current popped string with each word in dict
                // If any string follows similar pattern, push it into the queue
                for (int j = 0; j < word.size(); j++)
                {
                    // To find patterns, change every letter of word from a to z
                    // and check if that pattern exists with curr dict.
                    char o = word[j];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;
                        if (dict.find(word) != dict.end())
                        {
                            q.push(word);
                            // Push pattern, as well as erase it from dict.
                            // So that we don't repeat same pattern in same or later levels again.
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
};

// My Complicated Over-Optimization
class Solution2
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // Check if beginWord or endWord exists in wordList
        bool doesBegin = false, doesEnd = false;
        for (string word : wordList)
        {
            if (word == beginWord)
                doesBegin = true;
            if (word == endWord)
                doesEnd = true;
        }
        if (!doesEnd)
            return 0;
        if (!doesBegin)
            wordList.push_back(beginWord);

        // Sort them based on patterns
        unordered_map<string, vector<string>> patterns;
        for (string s : wordList)
            for (int i = 0; i < beginWord.size(); i++)
                patterns[s.substr(0, i) + "*" + s.substr(i + 1)].push_back(s);

        // Convert them into adj List
        unordered_map<string, vector<string>> adj;
        for (auto x : patterns)
            if (x.second.size() != 1)
                for (string s : x.second)
                    for (string z : x.second)
                        if (s != z)
                            adj[s].push_back(z);

        // Initialize BFS
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while (q.size())
        {
            for (int n = q.size(); n; n--)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return ans;
                if (visited.count(word))
                    continue;
                visited.insert(word);
                for (string s : adj[word])
                    q.push(s);
            }
            ans++;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList);
    return 0;
}

// https://leetcode.com/problems/word-ladder/