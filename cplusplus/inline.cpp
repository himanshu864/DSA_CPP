#include <iostream>
using namespace std;

inline int getMax(int &a, int &b)
{
    return (a >= b) ? a : b;
}

int main()
{
    int a = 3;
    int b = 2;

    int maxi = getMax(a, b);
    cout << maxi << endl;

    b += 2;

    maxi = getMax(a, b);
    cout << maxi << endl;

    return 0;
}
