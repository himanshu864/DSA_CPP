#include <iostream>
using namespace std;

void fnB(int n); // we need to declare fn before it is used, defination came come later

void fnA(int n)
{
    if (n <= 0)
        return;

    cout << n << " ";
    fnB(n - 1); // here fnB is used before it is defined hence it will give error
}

void fnB(int n) // fn is defined here
{
    if (n <= 1)
        return;

    cout << n << " ";
    fnA(n / 2);
}

int main()
{
    fnA(20);
    return 0;
}

// Indirect Recursion: when fns call each other in a cyclic manner
