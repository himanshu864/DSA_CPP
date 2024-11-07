#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int ans = 0;
        for (int i = 0; i < 24; i++)
        {
            int count = 0;
            for (int x : candidates)
                if ((x >> i) & 1)
                    count++;
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
    cout << sol.largestCombination(candidates) << endl;
    return 0;
}

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
