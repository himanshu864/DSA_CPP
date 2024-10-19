#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';

        int middle = pow(2, n - 1);
        if (k < middle)
            return findKthBit(n - 1, k);
        else if (k > middle)
            return (findKthBit(n - 1, 2 * middle - k) == '1') ? '0' : '1';
        else
            return '1';
    }
};

// Iterative - O(n) & O(1)
// here we keep halving string and store flips based on value of k
// flips represent inversion
class Solution2
{
public:
    char findKthBit(int n, int k)
    {
        bool flip = false;
        int size = (1 << n) - 1; // 2^n - 1
        while (k > 1)
        {
            int mid = size / 2 + 1;
            if (k == mid)
                return !flip ? '1' : '0';
            if (k > mid)
            {
                k = size - k + 1;
                flip = !flip;
            }
            size /= 2;
        }
        return flip ? '1' : '0';
    }
};

int main()
{
    Solution1 sol;
    int n = 4;
    int k = 11;
    cout << sol.findKthBit(n, k) << endl;
    return 0;
}

// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
