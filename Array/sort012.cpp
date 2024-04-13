#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    int a = 0;
    int b = n - 1;
    int c = 0;
    while (c < b)
    {
        if (arr[c] == 0)
            swap(arr[a++], arr[c++]);
        else if (arr[c] == 2)
            swap(arr[b--], arr[c]);
        else
            c++;
    }
}

int main()
{
    int size;
    cout << "Enter n: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter 0, 1 or 2 (n times): ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    sort012(arr, size);
    cout << "Sorted: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
