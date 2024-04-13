#include <iostream>
#include <vector>
using namespace std;

// iterative - O(n)
int fibonacci(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        b = b + a;
        a = b - a;
    }
    return a;
}

// recursive - O(2^n)
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

// recursion using memoization - O(n)
int f(int n)
{
    static vector<int> memory(n + 1, -1);
    memory[0] = 0;
    memory[1] = 1;

    if (memory[n] == -1)
        memory[n] = f(n - 1) + f(n - 2);
    return memory[n];
}

int main()
{
    int n = 5;
    cout << fibonacci(n) << endl;
    cout << fibo(n) << endl;
    cout << f(n) << endl;
    return 0;
}
