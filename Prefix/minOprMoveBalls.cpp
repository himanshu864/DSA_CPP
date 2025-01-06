#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> left(n);
        int ballsToLeft = 0;
        for (int i = 1; i < n; i++)
        {
            ballsToLeft += (boxes[i - 1] == '1');
            left[i] = left[i - 1] + ballsToLeft;
        }

        int ballsToRight = 0;
        vector<int> right(n);
        for (int i = n - 2; i >= 0; i--)
        {
            ballsToRight += (boxes[i + 1] == '1');
            right[i] = right[i + 1] + ballsToRight;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = left[i] + right[i];
        return ans;
    }
};

int main()
{
    int n = 4;
    cout << n << '\n';
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
