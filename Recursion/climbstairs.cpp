#include <bits/stdc++.h>
using namespace std;

long long int fact(long long int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
// basically draw all possible jumps of n = 5;
// 11111, 1112, 122 and their permutations
int countDistinctWays2(int nStairs)
{
    if (nStairs == 0)
        return 1;

    long long int ans = 0;
    long long int numones = nStairs;
    for (long long int numtwos = 0; numtwos * 2 <= nStairs; numtwos++, numones -= 2)
    {
        long long int combi = fact(numones + numtwos);
        combi /= fact(numones);
        combi /= fact(numtwos);
        ans += combi;
    }
    return ans;
}

int countDistinctWays(int nStairs)
{
    if (nStairs < 0)
        return 0;
    if (nStairs == 0)
        return 1;

    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

// my first try memoization solution
int helper(int n, vector<int> &memo)
{
    if (memo[n + 1] == -1)
        memo[n + 1] = helper(n - 1, memo) + helper(n - 2, memo);
    return memo[n + 1];
}
int climbStairs(int n)
{
    vector<int> memo(n + 2, -1);
    memo[0] = 0;
    memo[1] = 1;
    return helper(n, memo);
}

int main()
{
    int n = 5;
    cout << climbStairs(n);
    return 0;
}

// can only jump one or two steps
// return no. of distinct ways to climb from 0th to Nth stair
