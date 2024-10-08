#include <iostream>
#include <vector>
using namespace std;

/*
1. To make string balanced, while iterating string, whenever encounter extra closing bracket, swap with the rightmost opening bracket
2. We don't actually need to swap. Just count the number of maximum closing bracket at any given instant, and divide that by 2 get the mini swaps required
3. Watch the neetcode video to understand ig
*/

class Solution
{
public:
    int minSwaps(string s)
    {
        int maxi = 0;
        int closing = 0;
        for (char c : s)
        {
            closing += c == '[' ? -1 : 1;
            maxi = max(maxi, closing);
        }
        return (maxi + 1) / 2;
    }
};

int main()
{
    Solution sol;
    string s = "]]][[[";
    cout << sol.minSwaps(s) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
