#include <iostream>
#include <vector>
using namespace std;

void printSeries(int n, int k)
{
    cout << n << " ";
    if (n <= 0)
        return;
    printSeries(n - k, k);
    cout << n << " ";
}

int main()
{
    int n = 5, k = 2;
    printSeries(n, k);
    return 0;
}
