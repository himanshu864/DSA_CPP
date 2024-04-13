#include <iostream>
using namespace std;

void printplease(int arr[], int n, int start = 0)
{
    for (int i = start; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[5] = {3, 1, 5, 4, 2};
    printplease(arr, 5, 2);
    printplease(arr, 5);
    return 0;
}
