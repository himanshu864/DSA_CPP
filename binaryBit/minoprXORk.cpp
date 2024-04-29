#include <iostream>
#include <vector>
using namespace std;

// to find minimum no. of flips required to any element of nums, to make their xor == k
// Calculate the bitwise XOR of all elements of the original array and compare it to k in their binary representation.
// For each different bit between the bitwise XOR of elements of the original array and k we have to flip exactly one bit of an element in nums to make that bit equal.

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int x = 0;
        for (int i : nums)
            x ^= i;

        int ans = 0;
        while (k || x)
        {
            if (k % 2 != x % 2)
                ans++;
            k /= 2;
            x /= 2;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3, 4};
    int k = 1;
    cout << sol.minOperations(nums, k) << endl;
    return 0;
}
