#include <iostream>
#include <vector>
using namespace std;

/*
For Brute force: We'll fill the matrix start to bottom
Such that each col has it's best possible points as end.
Hence, for each col. Compare entire next row and decide best cell.
Time Complex = O(m * n * n) = O(n ^ 3). Also matrix might explode.

Hence, instead of checking entire row again and again for each col in a row
We'll precompute Left and Right best possible values.
Since we'll only be taking maximum point cells. We don't need to check entire row
Just check adjacent cells. i.e. In case of Left, compare cell directly above and (cell top left - 1)
Similarly compute Right. Choose max(left, right) for each col.
Time Complexity = O(m * 3 * n) = O(n ^ 2)

Kinda Like Double Dynamic Programming
Or just watch Neetcode Video to understand lol
*/

class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();
        vector<long long> sum(n);
        for (int j = 0; j < n; j++)
            sum[j] = points[0][j];

        for (int i = 1; i < m; i++)
        {
            // Pre-compute Left and Right. i.e. best points from above row
            vector<long long> left(n);
            left[0] = sum[0];
            for (int j = 1; j < n; j++)
                left[j] = max(sum[j], left[j - 1] - 1);

            vector<long long> right(n);
            right[n - 1] = sum[n - 1];
            for (int j = n - 2; j >= 0; j--)
                right[j] = max(sum[j], right[j + 1] - 1);

            // Sum will be current row + max(left, right)
            for (int j = 0; j < n; j++)
                sum[j] = points[i][j] + max(left[j], right[j]);
        }

        long long ans = 0;
        for (long long s : sum)
            ans = max(ans, s);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1},
    };
    cout << sol.maxPoints(points) << endl;
    return 0;
}

// https://leetcode.com/problems/maximum-number-of-points-with-cost/
