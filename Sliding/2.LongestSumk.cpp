#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    if (a.empty())
        return 0;

    int i = 0;
    int j = 0;
    long long sum = a[0];
    int ans = 0;

    while (j < a.size())
    {
        if (sum == k)
        {
            ans = max(ans, j - i + 1);
            j++;
            if (j < a.size())
                sum += a[j];
        }
        else if (sum < k)
        {
            j++;
            if (j < a.size())
                sum += a[j];
        }
        else
        {
            sum -= a[i];
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    long long targetSum = 3;
    int result = longestSubarrayWithSumK(arr, targetSum);
    cout << "Length of the longest subarray with sum " << targetSum << ": " << result << endl;
    return 0;
}
