#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// First try - 20th August 2024 - 6:11 PM - Graph is easy

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // Check if endWord exists in wordList
        bool flag = true;
        for (string word : wordList)
            if (word == endWord)
                flag = false;
        if (flag)
            return 0;

        // Convert to adj List
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < wordList.size(); i++)
            for (int j = i + 1; j < wordList.size(); j++)
            {
                string A = wordList[i], B = wordList[j];
                int count = 0;
                for (int k = 0; k < beginWord.size(); k++)
                    if (A[k] != B[k])
                        count++;
                if (count == 1)
                {
                    adj[A].push_back(B);
                    adj[B].push_back(A);
                }
            }

        // Initialize BFS
        queue<string> q;
        for (string word : wordList)
        {
            int count = 0;
            for (int k = 0; k < beginWord.size(); k++)
                if (word[k] != beginWord[k])
                    count++;
            if (count == 1)
                q.push(word);
        }

        // Start BFS with visited
        unordered_set<string> visited;
        visited.insert(beginWord);
        int ans = 2;
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
                for (string neigh : adj[word])
                    q.push(neigh);
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
