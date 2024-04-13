#include <iostream>
using namespace std;

void fn(int n)
{
    if (n <= 0)
        return;

    cout << n << " ";
    fn(n - 1);
    fn(n - 1);
}

int main()
{
    int n = 3;
    fn(3);
    return 0;
}

// Linear: fn calls itself only one time
// Tree: fn calls itself multiple times
// T.C: O(2^n) == no. of operations performed / size of tree
// S.C: O(n) == max height of stack / height of tree
