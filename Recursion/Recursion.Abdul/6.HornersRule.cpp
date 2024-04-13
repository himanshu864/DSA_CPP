#include <iostream>
using namespace std;

double eloop(double x, double n) // iterative
{
    double sum = 1;
    for (; n > 0; n--)
        sum = sum * (x / n) + 1;
    return sum;
}

double e(double x, double n) // tail-recursion
{
    static double sum = 1;
    if (n == 0)
        return sum;
    sum = sum * (x / n) + 1;
    return e(x, n - 1);
}

int main()
{
    double x = 1;
    double n = 10;
    cout << e(x, n) << endl;
    cout << eloop(x, n) << endl;
    return 0;
}

// e^x = 1 + x/1[1 + x/2[1 + x/3[1 + x/4[...]]]]
// taking common helps reduce no. of multiples, hence T.C = O(n) instead of O(n^2)
// notice here operations are being performed on calling time, hence easy loop
