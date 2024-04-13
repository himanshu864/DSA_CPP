#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {5, 3, 1, 8, 6};
    sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;

    int n;
    cout << "Enter n: ";
    cin >> n;

    auto lit = lower_bound(v.begin(), v.end(), n);
    auto uit = upper_bound(v.begin(), v.end(), n);

    if (lit == v.end())
        cout << "Not Found" << endl;
    else
        cout << "lower bound of n: " << *lit << endl;

    if (uit == v.end())
        cout << "Not Found" << endl;
    else
        cout << "upper bound of n: " << *uit << endl;

    return 0;
}

// Upper Bound and Lower Bound:
// We need a sorted array/vector. else time complexity O(N)
// upper/lower bound returns pointers in case of arrays. and iterators in case of vectors
// lower bound of 5 will return position of 5 or element greater than 5 within the range, else .end()
// upper bound of 5 will return position of element greater than 5 within the range, else .end()
// Time Complexity: O(logN) : Binary search
// use auto it = s.lower_bound(pos1, pos2, target); for sets and maps. else T.C: O(N) TLE
