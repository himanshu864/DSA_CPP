#include <iostream>
#include <vector>
using namespace std;

// buy one stock and sell it once for max profit

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int minLeft = 1e5;
        for (int i : prices)
        {
            minLeft = min(i, minLeft);
            ans = max(ans, i - minLeft);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 4, 3, 6, 5};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
