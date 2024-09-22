#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes)
    {
        long long ans = 0;
        // use minHeap to greedily find next smallest sum possible
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minHeap;
        for (int i : workerTimes)
            minHeap.push({i, 2, i});

        while (mountainHeight--)
        {
            long long sum = minHeap.top()[0];   // sum of time to be made
            long long steps = minHeap.top()[1]; // steps to be taken
            long long time = minHeap.top()[2];  // initial time
            minHeap.pop();
            ans = max(ans, sum);
            minHeap.push({sum + time * steps, steps + 1, time});
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int mountainHeight = 10;
    vector<int> workerTimes = {3, 2, 2, 4};
    cout << sol.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/