#include <iostream>
#include <vector>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

/*
Intuition:
    All the pivots elements are binary searchable
    i.e maxLeft<element<minRight;
*/

int binarySearchable(int arr[], int n)
{
    vector<int> maxLeft(n, 0), minRight(n, INT_MAX);
    int ans = 0;

    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxLeft[i] = maxi;
        maxi = max(arr[i], maxi);
    }

    int mini = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        minRight[i] = mini;
        mini = min(arr[i], mini);
    }

    for (int i = 0; i < n; i++)
        if (arr[i] <= minRight[i] && arr[i] >= maxLeft[i])
            ans++;

    return ans;
}

int main()
{
    int arr[6] = {1, 3, 5, 6, 9, 10};
    int k = 6;
    cout << binarysearch(arr, 6, k) << endl;
    cout << binarySearchable(arr, k) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/binary-searchable-elements/1
