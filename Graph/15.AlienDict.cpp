#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k)
{
    unordered_map<char, vector<char>> adj;
    vector<int> indegree(k);
    for (int i = 1; i < dictionary.size(); i++)
    {
        string A = dictionary[i - 1];
        string B = dictionary[i];

        int j = 0;
        while (j < A.size() && j < B.size() && A[j] == B[j])
            j++;
        if (j < A.size() && j < B.size() && A[j] != B[j])
        {
            adj[A[j]].push_back(B[j]);
            indegree[B[j] - 'a']++;
        }
    }

    queue<char> q;
    for (int i = 0; i < k; i++)
        if (indegree[i] == 0)
            q.push(i + 'a');

    string topoSort;
    while (q.size())
    {
        char x = q.front();
        q.pop();
        topoSort += x;
        for (char c : adj[x])
            if (--indegree[c - 'a'] == 0)
                q.push(c);
    }
    return topoSort;
}

int main()
{
    vector<string> dictionary = {"caa", "aaa", "aab"};
    int k = 3;
    cout << getAlienLanguage(dictionary, k);
    return 0;
}
