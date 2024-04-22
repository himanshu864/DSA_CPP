#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");
        for (int ans = 0; q.size(); ans++)
        {
            int n = q.size();
            while (n--)
            {
                string output = q.front();
                q.pop();

                if (output == target)
                    return ans;

                for (int i = 0; i < 4; i++)
                {
                    string up = output, down = output;
                    up[i] = (up[i] == '9') ? '0' : (up[i] + 1);
                    down[i] = (down[i] == '0') ? '9' : (down[i] - 1);

                    if (!visited.count(up))
                    {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!visited.count(down))
                    {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    cout << sol.openLock(deadends, target) << endl;
}

// https://leetcode.com/problems/open-the-lock
