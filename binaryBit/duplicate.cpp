#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++) // XORing entire array gives 1^2^3^...x^...^(n-1) ^ x
        ans = ans ^ arr[i];     // Since x ^ x = 0, we're left with 1 to (n-1) without x

    for (int i = 0; i < n; i++) // Now if we XOR that with 1 to (n-1) with x, we'll be left with only x
        ans = ans ^ i;

    return ans;
}

int main()
{
    int arr[6] = {5, 3, 2, 1, 3, 4};
    cout << findDuplicate(arr, 6);
    return 0;
}
