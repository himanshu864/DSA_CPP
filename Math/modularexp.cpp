#include <bits/stdc++.h>
using namespace std;

int modularExpo(int x, int n, int m)
{
    int ans = 1;
    while (n > 0)
    {
        if (n & 1) // odd
        {
            ans = (1LL * (ans) * (x) % m) % m;
            //%m did this so that it gets in the range.
            // multiplied with 1LL(1longlong) because if didnt, it would get  out of the range of int ,so typecasted it.
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1; // didnt directly divided by 2, instead used right shift,  because it's a better practice.
    }
    return ans;
}

int main()
{
    int x = 12;
    int n = 11;
    int m = 1e6;
    cout << modularExpo(x, n, m) << endl;
    return 0;
}
