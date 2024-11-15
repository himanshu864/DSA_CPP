#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int j = n - 1;
        // Move right pointer `j` to start of non-decreasing suffix
        // Identify non-decreasing suffix
        while (j > 0 && arr[j - 1] <= arr[j])
            j--;

        // If entire array is already non-decreasing, return 0
        if (j == 0)
            return 0;

        // Calculate initial answer by removing entire middle subarray
        int ans = j; // Removing everything from `i = 0` to `j - 1`

        // Use two-pointer approach to try and minimize subarray to remove
        // Ensure prefix is non-decreasing
        for (int i = 0; i < n && (i == 0 || arr[i] >= arr[i - 1]); i++)
        {
            while (j < n && arr[i] > arr[j])
                j++;
            ans = min(ans, j - i - 1); // remove everything in b/w i and j
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 10, 9, 1, 2, 3};
    // vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    // vector<int> arr = {1, 3, 5, 6};
    // vector<int> arr = {6, 3, 1};
    // vector<int> arr = {1, 3, 2, 4};
    cout << sol.findLengthOfShortestSubarray(arr) << endl;
    return 0;
}

// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
