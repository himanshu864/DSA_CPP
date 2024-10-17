#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Recursion
class Solution
{
public:
    int perfectSum(int arr[], int n, int sum)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        int pick = perfectSum(arr, n - 1, sum - arr[n - 1]);
        int notpick = perfectSum(arr, n - 1, sum);
        return pick + notpick;
    }
};

int main()
{
    Solution sol;
    int arr[] = {5, 2, 3, 10, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << sol.perfectSum(arr, n, sum) << endl;
    return 0;
}
