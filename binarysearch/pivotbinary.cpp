#include <iostream>
using namespace std;

int getPivot(int arr[], int n)
{
    int s = 0, e = n - 1;

    if (arr[s] <= arr[e])
        return 0;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int main()
{
    int arr[6] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << "Pivot is " << getPivot(arr, n) << endl;
}
