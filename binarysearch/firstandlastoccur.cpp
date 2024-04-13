#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = -1, last = -1;

    int si = 0, ei = n - 1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;

        if (arr[mid] == k)
        {
            first = mid;
            ei = mid - 1; // Move left to find the leftmost occurrence
        }
        else if (arr[mid] < k)
            si = mid + 1;
        else
            ei = mid - 1;
    }

    si = 0, ei = n - 1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;

        if (arr[mid] == k)
        {
            last = mid;
            si = mid + 1; // Move right to find the rightmost occurrence
        }
        else if (arr[mid] < k)
            si = mid + 1;
        else
            ei = mid - 1;
    }

    return make_pair(first, last);
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the sorted array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the target value: ";
    cin >> k;

    pair<int, int> result = firstAndLastPosition(arr, n, k);

    cout << "First occurrence: " << result.first << endl;
    cout << "Last occurrence: " << result.second << endl;

    return 0;
}

// https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM