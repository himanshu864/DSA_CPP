#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &stones, unordered_set<int> &visited, int s1)
    {
        visited.insert(s1);
        // stone with same row or column, group them into island
        for (int i = 0; i < stones.size(); i++)
            if (!visited.count(i))
                if (stones[s1][0] == stones[i][0] || stones[s1][1] == stones[i][1])
                    dfs(stones, visited, i);
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int numOfIslands = 0;
        unordered_set<int> visited;
        for (int i = 0; i < stones.size(); i++)
            if (!visited.count(i))
            {
                dfs(stones, visited, i); // Start DFS if the stone is not visited
                numOfIslands++;          // Increment the number of connected components
            }
        return stones.size() - numOfIslands;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << sol.removeStones(stones);
    return 0;
}

// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
