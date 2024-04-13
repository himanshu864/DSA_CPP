#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // dynamic array
    vector<int> v; // initialize vector

    cout << "Size: " << v.size() << endl;         // no. of elements inside vector
    cout << "Capacity: " << v.capacity() << endl; // number of memory assigned

    v.push_back(5);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(6);
    cout << "Capacity: " << v.capacity() << endl;

    v.push_back(7);
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    cout << " > Vector: ";
    for (auto i : v) // auto can be used for any datatype
        cout << i << " ";
    cout << endl;

    cout << "Element at index 1: " << v.at(1) << endl;
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    v.pop_back();
    cout << " > Vector after pop_back: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;

    v.clear();
    cout << " > Vector after clearing: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Is Empty: " << v.empty() << endl;

    // to initialize vector of size 5 with each element 1.(default == 0)
    vector<int> arr(5, 1);
    cout << "arr : ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    cout << "capacity: " << arr.capacity() << endl;
    arr.push_back(1);
    cout << "capacity after pushing another 1: " << arr.capacity() << endl;
    arr.shrink_to_fit();
    cout << "capacity after shrinking: " << arr.capacity() << endl;

    // to copy entire vector to another
    vector<int> vect2(arr);
    cout << "vect2 : ";
    for (int i : vect2)
        cout << i << " ";
    cout << endl;

    // swap 2 vectors
    vector<int> hector = {1, 2, 3, 4};
    hector.swap(vect2);
    cout << "hector : ";
    for (int i : hector)
        cout << i << " ";
    cout << endl;
    cout << "vect2 : ";
    for (int i : vect2)
        cout << i << " ";
    cout << endl;

    // iteration
    vector<int>::iterator it;
    it = vect2.end();

    // v.insert(position, iteration1, iterator2) for ranged insertion
    vect2.insert(it, hector.begin(), hector.begin() + 3);
    cout << "vect2 : ";
    for (int i : vect2)
        cout << i << " ";
    cout << endl;

    // v.erase(position1, position2)
    vect2.erase(vect2.end() - 3, vect2.end());
    cout << "vect2 : ";
    for (int i : vect2)
        cout << i << " ";
    cout << endl;

    return 0;
}
