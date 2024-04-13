#include <iostream>
using namespace std;

int fourkipower(int x) // using recursion to find 4 to the power x
{
    if (x == 0)
        return 1;
    return 4 * fourkipower(x - 1);
}

bool isPowerOfFour(int n) // bit manipulation to check if n is power of four
{
    return n > 0 && (n & (n - 1)) == 0 && ((n - 1) % 3) == 0;
}

int main()
{
    int x = 5;
    int n = fourkipower(x);
    cout << n << " ";
    cout << (isPowerOfFour(n) ? "Yes" : "Nope") << endl;

    n = 8;
    cout << n << " ";
    cout << (isPowerOfFour(n) ? "Yes" : "Nope") << endl;

    return 0;
}

// n > 0 for -ve and zero edge cases
// (n & (n - 1)) == 0 for checking if power of 2
// (n - 1) % 3 == 0 for checking power of 4
