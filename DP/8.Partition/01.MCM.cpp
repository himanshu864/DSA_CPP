#include <iostream>
#include <vector>
using namespace std;

/*
Partition DP
when multiple ways to solve a problem
multiple partitions k from i (start) to j (end)
and return best answer
*/

/*
Eg: {a, b, c, d, e} are 4 matrices => ab, bc, cd, de
can multiply like -> ((AB)C)D or (AB)(CD) or (A(BC))D or A((BC)D) or A(B(CD))
Again Recursively break problem down into smaller chunks
Best way to multiply ABCD -> (A)(BCD) or (AB)(CD) or (ABC)(D)
now solve for (BCD) -> (BC)(D) or (B)(CD) and so on
let i and j be starting and ending indices representing matrix
since given in terms of sizes i = 1 & j = n - 1
matrix[i] = arr[i - 1] * arr[i];
*/

class Solution1
{
    // return minimum no. of matrix multiplications
    int f(int i, int j, int arr[])
    {
        if (i == j) // no multiplication for single matrix
            return 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            // this is brilliant. say arr = {4, 2, 3, 1} and i = 1 & j = 3
            // we have 3 matrices. [A]42 [B]23 [C]31 => no matter what we multiply first
            // the resultant matrix will have dimensions []41
            // and depending on how we partition. we have to return no. of multiplications on this level
            // eg: if k == 1 =>  saying A(BC) => [A]42 * [BC]21 => 4 * 2 * 1 no. of multiplications + f(1, 1) + f(2, 3)
            int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr) + f(k + 1, j, arr);
            ans = min(ans, steps);
        }
        return ans;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        return f(1, N - 1, arr);
    }
};

// Memoization
class Solution2
{
    int f(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;

        if (dp[i][j] == -1)
        {
            int ans = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr, dp) + f(k + 1, j, arr, dp);
                ans = min(ans, steps);
            }
            dp[i][j] = ans;
        }
        return dp[i][j];
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N - 1, arr, dp);
    }
};

// Tabulation
class Solution3
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        /*
        Recursion went from (1, n - 1) to (i, i) base case
        i was increasing and j decreasing
        hence, bottom up is opposite direction
        */
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 2; i > 0; i--)
            for (int j = i + 1; j < N; j++)
            {
                int ans = INT_MAX;
                for (int k = i; k < j; k++)
                    ans = min(ans, (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j]);
                dp[i][j] = ans;
            }
        return dp[1][N - 1];
    }
};

int main()
{
    Solution3 sol;
    int arr[] = {40, 20, 30, 10, 30};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << sol.matrixMultiplication(N, arr) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/
