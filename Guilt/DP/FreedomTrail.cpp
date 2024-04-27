#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        vector<int> pos[26];
        int r = ring.size();
        for (int i = 0; i < r; i++)
            pos[ring[i] - 'a'].push_back(i);
        vector<vector<int>> mem(r, vector<int>(key.size()));
        return findSteps(0, 0, ring, key, pos, mem);
    }
    int findSteps(int p1, int p2, string &ring, string &key,
                  vector<int> pos[26], vector<vector<int>> &mem)
    {
        if (p2 == key.size())
            return 0;
        if (mem[p1][p2])
            return mem[p1][p2];
        int r = ring.size(), ms = INT_MAX;
        for (int nxt : pos[key[p2] - 'a'])
        {
            int dist = abs(p1 - nxt);
            ms = min(ms, min(dist, r - dist) + findSteps(nxt, p2 + 1, ring, key, pos, mem));
        }
        return mem[p1][p2] = ms + 1;
    }
};

int main()
{
    Solution sol;
    string ring = "himanshu";
    string key = "human";
    cout << sol.findRotateSteps(ring, key) << endl;
    return 0;
}

// https://leetcode.com/problems/freedom-trail/
