#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        // Minimize xor, we'll optimally try to make x the same as num1
        // but since no. of bits are set. We handle extra or lacking by modifying num1
        int bitCount = __builtin_popcount(num2);
        bitCount -= __builtin_popcount(num1);
        if (bitCount < 0) // less bits. Turn 1's to 0 : R -> L
        {
            bitCount *= -1;
            while (bitCount--)
                num1 &= (num1 - 1);
        }
        if (bitCount > 0) // extra bits. Turn 0's to 1 :  R -> L
        {
            while (bitCount--)
                num1 |= (num1 + 1);
        }
        return num1;
    }
};

int main()
{
    Solution sol;
    int num1 = 3;
    int num2 = 5;
    cout << sol.minimizeXor(num1, num2) << endl;
    return 0;
}

// https://leetcode.com/problems/minimize-xor/
