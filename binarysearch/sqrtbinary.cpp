#include <iostream>
using namespace std;

int sqrtINT(int x)
{
    if (x < 2)
        return x;

    int s = 1, e = x / 2;
    int ans;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (mid > x / mid)
            e = mid - 1;
        else if (mid < x / mid)
        {
            ans = mid; // save floor value
            s = mid + 1;
        }
        else
            return mid;
    }
    return ans;
}

double sqrtDecimal(int x, int IntegerPart)
{
    double ans = (double)IntegerPart;
    double factor = 1;

    for (int i = 0; i < 4; i++)
    {
        factor /= 10;
        while ((ans + factor) * (ans + factor) < (double)x)
            ans += factor;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int IntegerPart = sqrtINT(n);
    cout << "Integer part: " << IntegerPart << endl;
    cout << "With 4 Decimals: " << sqrtDecimal(n, IntegerPart) << endl;
    return 0;
}
