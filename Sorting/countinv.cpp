#include <bits/stdc++.h>
using namespace std;

void twoway(vector<int> &arr, int &ans, int s, int mid, int e)
{
    vector<int> first(arr.begin() + s, arr.begin() + mid + 1);
    vector<int> second(arr.begin() + mid + 1, arr.begin() + e + 1);
    int x = s;
    int a = 0, b = 0;
    while (a < first.size() && b < second.size())
    {
        if (first[a] <= second[b])
            arr[x++] = first[a++];
        else
        {
            // here b is smaller than all elements to the right of a in first array
            ans += (mid - a - s + 1); // I am goddamn genuis
            arr[x++] = second[b++];
        }
    }
    while (a < first.size())
        arr[x++] = first[a++];
    while (b < second.size())
        arr[x++] = second[b++];
}

void merge(vector<int> &arr, int &ans, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    merge(arr, ans, s, mid);
    merge(arr, ans, mid + 1, e);
    twoway(arr, ans, s, mid, e);
}

int numberOfInversions(vector<int> &a, int n)
{
    int ans = 0;
    merge(a, ans, 0, n - 1);
    return ans;
}

int main()
{
    vector<int> a = {5, 3, 2, 1, 4};
    cout << numberOfInversions(a, a.size()) << endl;
    for (int i : a)
        cout << i << " ";
    return 0;
}

// https://www.codingninjas.com/studio/problems/number-of-inversions_6840276
