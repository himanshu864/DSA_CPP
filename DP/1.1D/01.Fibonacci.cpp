#include <iostream>
#include <vector>
using namespace std;

// recursive - O(2^n) & O(1)
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

// recursion using memoization - O(n) & O(n)
class MF
{
    vector<int> dp = {0, 1};
    int f(int n)
    {
        if (dp[n] == -1)
            dp[n] = f(n - 1) + f(n - 2);
        return dp[n];
    }

public:
    int fibonacci(int n)
    {
        if (dp.size() > n && dp[n] != -1)
            return dp[n];
        dp.resize(n + 1, -1);
        return f(n);
    }
};

// Tabulation - O(n) & O(n)
int fibona(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Space Optimization (iteration) - O(n) & O(1)
int fibonacci(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        b = b + a;
        a = b - a;
    }
    return a;
}

int main()
{
    MF mf;
    int n = 5;
    cout << fibonacci(n) << endl;
    cout << fibo(n) << endl;
    cout << fibona(n) << endl;
    cout << mf.fibonacci(n) << endl;
    return 0;
}

// https://leetcode.com/problems/climbing-stairs/
