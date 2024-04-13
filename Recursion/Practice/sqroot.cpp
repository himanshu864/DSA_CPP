#include <iostream>
#include <vector>
using namespace std;

int assist(int ans, int s, int e, int n)
{
    if (s > e)
        return ans;
    int mid = (s + (e - s) / 2);
    if (mid * mid == n)
        return mid;
    else if (mid * mid > n)
        return assist(ans, s, mid - 1, n);
    else
    {
        return assist(mid, mid + 1, e, n);
    }
}

int sqrtplease(int n)
{
    if (n < 2)
        return n;
    return assist(1, 1, n, n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << sqrtplease(n) << endl;
    return 0;
}
