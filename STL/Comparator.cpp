#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] > b[0]; // for descending first elements
}

bool bluetooth(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second; // decending second
    return a.first < b.first;       // ascending firsts
}

int main()
{
    cout << "Vector-vector custom sorting: " << endl;
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    sort(points.begin(), points.end(), comp);
    for (vector<int> p : points)
    {
        for (int i : p)
            cout << i << " ";
        cout << endl;
    }

    cout << "Vector-pair custom sorting: " << endl;
    vector<pair<int, int>> eg = {{1, 3}, {3, 6}, {4, 5}, {2, 4}, {3, 1}, {3, 3}};
    sort(eg.begin(), eg.end(), bluetooth);
    for (pair<int, int> p : eg)
        cout << p.first << " " << p.second << endl;
    return 0;
}
