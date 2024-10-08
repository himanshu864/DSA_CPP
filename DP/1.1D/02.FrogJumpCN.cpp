#include <iostream>
#include <vector>
using namespace std;

/*
If have to check all possible paths via - best way or total ways
RECURSION! or rather Dynamic Programming!

# Striver's Way: (I don't like it)
- Then use following abstract steps to find out recursive relation

1. Try to represent problem in terms of indices
2. Do stuff on those indices according to problem
3. if asked total ways = sum indices or min/max indices

# Recursion Magic Way: (I like it)

1. Recursion will magically solve smaller sub-problems.
2. Just define base cases and
3. Solve for only f(n) one step
*/

// Top Down - Recursion - O(2^n) & O(n)
class SolutionRecursive
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return abs(height[1] - height[0]);
        int one = minimumEnergy(height, n - 1) + abs(height[n - 1] - height[n - 2]);
        int two = minimumEnergy(height, n - 2) + abs(height[n - 1] - height[n - 3]);
        return min(one, two);
    }
};

// Top Down - Memoization - O(n) time & O(n) space
class SolutionMemoization
{
    int f(int n, vector<int> &height, vector<int> &dp)
    {
        if (dp[n] == -1)
        {
            int onestep = f(n - 1, height, dp) + abs(height[n] - height[n - 1]);
            int twostep = f(n - 2, height, dp) + abs(height[n] - height[n - 2]);
            dp[n] = min(onestep, twostep);
        }
        return dp[n];
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        return f(n - 1, height, dp);
    }
};

// Bottom Up - Tabulation - O(n) time & O(n) space
class SolutionTabulation
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            int onestep = dp[i - 1] + abs(height[i] - height[i - 1]);
            int twostep = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(onestep, twostep);
        }
        return dp[n - 1];
    }
};

// Bottom Up - Space Optimization - O(n) & O(1)
class SolutionSpaceOptimation
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        if (n == 1)
            return 0;
        int secondlast = 0;
        int last = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++)
        {
            int curr = min(last + abs(height[i] - height[i - 1]), secondlast + abs(height[i] - height[i - 2]));
            secondlast = last;
            last = curr;
        }
        return last;
    }
};

int main()
{
    int n = 4;
    vector<int> height = {10, 20, 30, 10};
    SolutionRecursive rec;
    cout << rec.minimumEnergy(height, n) << endl;
    SolutionMemoization mem;
    cout << mem.minimumEnergy(height, n) << endl;
    SolutionTabulation tab;
    cout << tab.minimumEnergy(height, n) << endl;
    SolutionSpaceOptimation spa;
    cout << spa.minimumEnergy(height, n) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/geek-jump/1
