#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;

        set<pair<int, int>> visited;
        queue<pair<int, int>> q; // {scene, buffer}
        q.push({1, 1});
        for (int ans = 1; q.size(); ans++)
            for (int x = q.size(); x; x--)
            {
                int scene = q.front().first;
                int buffer = q.front().second;
                q.pop();

                if (scene == n) // height of tree is ans
                    return ans;
                if (scene + buffer > n) // no longer possible
                    continue;
                if (visited.count({scene, buffer}))
                    continue;
                visited.insert({scene, buffer});

                if (scene == buffer) // only paste possible
                    q.push({2 * scene, scene});
                else
                {
                    q.push({scene, scene});           // copy
                    q.push({scene + buffer, buffer}); // paste
                }
            }
        return -1;
    }
};

// Optimize

int main()
{
    Solution sol;
    int n = 3;
    cout << sol.minSteps(n) << endl;
    return 0;
}

// https://leetcode.com/problems/2-keys-keyboard
