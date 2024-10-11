#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        // Use minHeap to sort based on {time, index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> exit;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> enter;

        // minHeap for empty chairs
        priority_queue<int, vector<int>, greater<int>> chairs;

        for (int i = 0; i < times.size(); i++)
        {
            enter.push({times[i][0], i});
            exit.push({times[i][1], i});
            chairs.push(i);
        }

        // hash[index] = chair
        unordered_map<int, int> seating;

        // time at which targetFriend sits
        int x = times[targetFriend][0];

        while (enter.size())
        {
            // exit all before entering
            if (exit.top()[0] <= enter.top()[0])
            {
                chairs.push({seating[exit.top()[1]]});
                exit.pop();
            }
            else
            {
                if (enter.top()[0] == x)
                    return chairs.top();
                seating[enter.top()[1]] = chairs.top();
                chairs.pop();
                enter.pop();
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend = 1;
    cout << sol.smallestChair(times, targetFriend) << endl;
    return 0;
}

// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
