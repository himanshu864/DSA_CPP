#include <iostream>
#include <vector>
using namespace std;

/*
Partition DP problem. Partition at operators
Eg: T^T|F|T can be solved as (T)^(T|F|T) or (T^T)|(F|T) or (T^T|F)|(T)
and for each partition, we need to figure out no. of ways it returns True and False individually
since then we can add up all possibilites to based on operator to make expression == flag

eg: for & to be true => both must be true, hence total no. of ways => t1 * t2
eg: for | to be true => any one must be true
eg: for ^ to be false => both must be same
and so on.

Now simply call recursion for all these possibilites, and return total no. of ways to make TRUE
*/

// Recursion
class Solution1
{
    // numbers of ways to parenthesis exp[i -> j] to evaluate to flag
    int f(int i, int j, bool makeTrue, string &exp)
    {
        if (i == j)
        {
            if (makeTrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }

        int ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            int t1 = f(i, k - 1, true, exp);
            int f1 = f(i, k - 1, false, exp);
            int t2 = f(k + 1, j, true, exp);
            int f2 = f(k + 1, j, false, exp);

            if (exp[k] == '&')
            {
                if (makeTrue)
                    ans += (t1 * t2);
                else
                    ans += (f1 * f2) + (t1 * f2) + (f1 * t2);
            }
            else if (exp[k] == '|')
            {
                if (makeTrue)
                    ans += (t1 * t2) + (t1 * f2) + (f1 * t2);
                else
                    ans += (f1 * f2);
            }
            else
            {
                if (makeTrue)
                    ans += (t1 * f2) + (f1 * t2);
                else
                    ans += (t1 * t2) + (f1 * f2);
            }
        }
        return ans;
    }

public:
    int evaluateExp(string &exp)
    {
        return f(0, exp.size() - 1, true, exp);
    }
};

// Memoization
class Solution2
{
    int mod = 1e9 + 7;
    int f(int i, int j, bool makeTrue, string &exp, vector<vector<vector<int>>> &dp)
    {
        if (i == j)
        {
            if (makeTrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }

        if (dp[i][j][makeTrue] != -1)
            return dp[i][j][makeTrue];

        long long ans = 0;
        for (int k = i + 1; k < j; k += 2)
        {
            long long t1 = f(i, k - 1, true, exp, dp);
            long long f1 = f(i, k - 1, false, exp, dp);
            long long t2 = f(k + 1, j, true, exp, dp);
            long long f2 = f(k + 1, j, false, exp, dp);

            if (exp[k] == '&')
            {
                if (makeTrue)
                    ans = ((t1 * t2) % mod + ans) % mod;
                else
                    ans = ((f1 * f2) % mod + (t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
            }
            else if (exp[k] == '|')
            {
                if (makeTrue)
                    ans = ((t1 * t2) % mod + (t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
                else
                    ans = ((f1 * f2) % mod + ans) % mod;
            }
            else
            {
                if (makeTrue)
                    ans = ((t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
                else
                    ans = ((t1 * t2) % mod + (f1 * f2) % mod + ans) % mod;
            }
        }
        return dp[i][j][makeTrue] = ans;
    }

public:
    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(0, n - 1, true, exp, dp);
    }
};

// Tabulation
class Solution3
{
    int mod = 1e9 + 7;

public:
    int evaluateExp(string &exp)
    {
        int n = exp.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
        for (int i = 0; i < n; i += 2)
        {
            dp[i][i][0] = exp[i] == 'F';
            dp[i][i][1] = exp[i] == 'T';
        }
        for (int i = n - 3; i >= 0; i -= 2)
            for (int j = i + 2; j < n; j += 2)
                for (int makeTrue = 0; makeTrue <= 1; makeTrue++)
                {
                    long long ans = 0;
                    for (int k = i + 1; k < j; k += 2)
                    {
                        long long t1 = dp[i][k - 1][1];
                        long long f1 = dp[i][k - 1][0];
                        long long t2 = dp[k + 1][j][1];
                        long long f2 = dp[k + 1][j][0];

                        if (exp[k] == '&')
                        {
                            if (makeTrue)
                                ans = ((t1 * t2) % mod + ans) % mod;
                            else
                                ans = ((f1 * f2) % mod + (t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
                        }
                        else if (exp[k] == '|')
                        {
                            if (makeTrue)
                                ans = ((t1 * t2) % mod + (t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
                            else
                                ans = ((f1 * f2) % mod + ans) % mod;
                        }
                        else
                        {
                            if (makeTrue)
                                ans = ((t1 * f2) % mod + (f1 * t2) % mod + ans) % mod;
                            else
                                ans = ((t1 * t2) % mod + (f1 * f2) % mod + ans) % mod;
                        }
                    }
                    dp[i][j][makeTrue] = ans;
                }
        return dp[0][n - 1][1];
    }
};

int main()
{
    Solution3 sol;
    // string exp = "T^T|F|T";
    string exp = "F&F|F^T|F|T|T";
    cout << sol.evaluateExp(exp) << endl;
    return 0;
}

// https://www.naukri.com/code360/problems/boolean-evaluation_1214650
