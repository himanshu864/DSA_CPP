#include <iostream>
using namespace std;

void updateit(int n)
{
    n++;
}

void updateplease(int &n)
{
    n++;
}

void swapplease(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 5;
    // creating a reference variable.
    int &j = i;
    cout << "i: " << i << " and j: " << j << endl;
    j++;
    cout << i << " " << j << endl;
    i++;
    cout << i << " " << j << endl;

    int x = 10;
    cout << "x: " << x << endl;
    updateit(x);
    cout << x << endl;
    updateplease(x);
    cout << x << endl;

    swapplease(x, i);
    cout << "x: " << x << " and j: " << i << endl;
    return 0;
}
