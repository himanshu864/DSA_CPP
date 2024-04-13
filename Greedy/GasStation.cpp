#include <iostream>
#include <vector>
using namespace std;

// Brute Force, check for each point if cycle sum >= 0. O(n^2)
// Optimize, if any starting point has highest cost then gas, not possible
// Moveover, if total gas < total cost. No starting point will complete a cycle. Hence -1.
// Else it's guaranteed that only one solution exists.

// Hence, we travel through gas summing difference and restarting if sum < 0
// 2 Big brain inituitions:
//      1. Say if, A starting gas station, could only reach gas station D, before running out of money. Any station in between also won't make it
//         As A was bringing atleast some gas fuel with it as (gas[i] - cost[i]) >= 0. Hence, any station will run out too.

//      2. If any starting point reaches end of gas, we don't need to cycle to front and check any further
//          as if total gas >= total cost. there must exist a unique solution. and any point in front of start will have less gas
//          therefore, difference after that starting station must be enough to complete a cycle, hence ans
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int ans = 0, sum = 0, total = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            total += (gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if (sum < 0)
            {
                sum = 0;
                ans = i + 1;
            }
        }
        return (total < 0) ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}

// https://leetcode.com/problems/gas-station/
