#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 5;
    cout << "number: " << n << endl;

    if (n == 0)
        return 1;

    int mask = 0;
    int m = n;
    for (int m = n; m; m = m >> 1)
    {
        mask = (mask << 1) | 1; // Now, we have created a binary number 0...0111 with 1 being the no. of bits in n
    }
    int ans = (~n) & mask; // We'll get the compliment if we &(AND) ~n and mask.
    cout << ans << endl;

    int also = n ^ mask; // we could also XOR n and mask too.
    cout << also << endl;

    /*
    int temp = 0;
    for (int i = n; i > 0; i = i >> 1)
        temp++;
    int mask2 = pow(2, temp) - 1;
    int res = n ^ mask2;
    cout << res << endl;
    */

    return 0;
}

// https://leetcode.com/problems/number-complement/
