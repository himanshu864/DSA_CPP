#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {5, 3, 1, 8, 6, 3};

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int i : v)
        cout << i << " ";
    cout << endl;

    cout << "Binary search for 4: " << binary_search(v.begin(), v.end(), 4) << endl;
    cout << "Binary search for 5: " << binary_search(v.begin(), v.end(), 5) << endl;

    auto lit = lower_bound(v.begin(), v.end(), 6);
    cout << "lower bound of 6: " << *lit << endl;
    auto uit = upper_bound(v.begin(), v.end(), 6);
    cout << "upper bound of 6: " << *uit << endl;

    int maxi = *max_element(v.begin(), v.end());
    cout << "max: " << maxi << endl;

    int mini = *min_element(v.begin(), v.end());
    cout << "min: " << mini << endl;

    int sum = accumulate(v.begin(), v.end() - 2, 0);
    cout << "sum of start to end-2: " << sum << endl;

    int c = count(v.begin(), v.end(), 3);
    cout << "count of 3: " << c << endl;

    reverse(v.begin() + 2, v.end());
    cout << "reversing begin+2 to end: ";
    for (int i : v)
        cout << i << " ";
    cout << endl;

    sort(v.begin(), v.end());
    cout << "Rotating sorted vector to left by 2: ";
    rotate(v.begin(), v.begin() + 2, v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;

    sort(v.begin(), v.end());
    cout << "Rotating sorted vector to right by 2: ";
    rotate(v.begin(), v.begin() + v.size() - 2, v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}

// Note: we can use v.begin() + 1 in cases of array/vectors
// v.begin() turns to arr, v.end() turns to arr + n. (in case of arrays)

// Algorithms: Pre-defined functions
// sort() uses Introsort: quick sort, heap sort, insertion sort: T.C: O(NlogN)
// binary_search returns 1(true) is target is present, else 0: T.C: O(logN)
// vector should be sorted for BS, else T.C: O(N)
// we know lower/upper_bound, find, count, erase, etc

// max_element() returns position of max element. i.e. pointer/iterator
// hence use * deference to get element. similar to find()

// accumulate using <numeric> header, and gives sum of range
// we need to enter initial sum, 0 in our case

// Time Complexity is O(N) for above function in case of array/vector

// Reverse: reverses range, int/string whatever
// Rotate(first, mid, last)
// For left: middle = v.begin() + rot : elements from first to mid are rotated to end
// For right: middle = v.begin() + v.size() - rot : elements from mid to last are rotated to start
