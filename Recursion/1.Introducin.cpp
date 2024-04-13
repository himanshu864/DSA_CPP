#include <iostream>
using namespace std;

long long int fibonnaci(int n)
{
    if (n < 2)
        return n;
    return fibonnaci(n - 1) + fibonnaci(n - 2);
}

long long int twokipower(int n)
{
    if (n == 0)
        return 1;
    return 2 * twokipower(n - 1);
}

long long int factorial(int n)
{
    // base case
    if (n == 0)
        return 1;
    // recursive relation
    return n * factorial(n - 1);
}

void countalso(int n, int start = 1)
{
    if (start == n + 1)
        return;
    cout << start << endl; // tail recursion with default argument
    return countalso(n, start + 1);
}

void count(int n)
{
    if (n == 0)
        return;
    count(n - 1);      // notice no return for
    cout << n << endl; // head recursion
}

bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
        return true;
    if (arr[n - 2] > arr[n - 1])
        return false;
    return isSorted(arr, n - 1);
}

bool isSortedalso(int arr[], int n) // my way using pointers
{
    if (n == 0 || n == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    return isSortedalso(arr + 1, n - 1);
}

int sumplease(int arr[], int n)
{
    if (n == 0)
        return 0;
    return arr[0] + sumplease(arr + 1, n - 1);
}

int main()
{
    int a;
    cout << "Enter a small number: ";
    cin >> a;
    cout << "fibonnaci: " << fibonnaci(a) << endl;
    cout << "twokipower: " << twokipower(a) << endl;
    cout << "factorial: " << factorial(a) << endl;
    cout << "Counting-->" << endl;
    count(a);

    cout << endl
         << "Checking if array is sorted: ";
    // int arr[6] = {3, 4, 5, 9, 10, 2};
    int arr[6] = {3, 4, 5, 9, 10, 12};
    cout << (isSorted(arr, 6) ? "YUP" : "NOPE") << " ";
    cout << (isSortedalso(arr, 6) ? "YUP" : "NOPE") << endl;
    cout << "Sum: " << sumplease(arr, 6) << endl;
    return 0;
}
