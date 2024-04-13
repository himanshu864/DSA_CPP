#include <iostream>
#include <array>
using namespace std;

int main()
{
    int arr[3] = {1, 2, 3}; // basic array (static)

    array<int, 4> a = {5, 6, 7, 8}; // STL array (also static)

    for (int i : a) // short for iterating from begin() to end()
        cout << i << " ";
    cout << endl;

    cout << a.size() << endl;  // returns size of array
    cout << a.empty() << endl; // returns true if array is empty
    cout << a.front() << endl; // returns element at first index
    cout << a.back() << endl;  // returns element at last index
    return 0;
}
