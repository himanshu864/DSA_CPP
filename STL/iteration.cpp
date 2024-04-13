#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2, 3, 5, 7, 9};

    vector<int>::iterator it = v.begin();

    while (it != v.end())
    {
        cout << *it << endl;
        it++;
    }

    vector<pair<int, int>> vecp = {{1, 2}, {3, 4}};
    for (auto i : vecp)
        cout << i.first << " " << i.second << endl;

    return 0;
}

// iterators are similar to pointers.
// iterators points towards position of element
// example .begin() points towards the first element
// while .end() points towards the element next to last
// deference it using * to access the element
// we can (it++) but can't (it+1), as it+1 brings you to next location,
// and memory isn't contigous in cases like map, set, etc.
// it++ brings you to the next element. hence use that instead
// auto defects datatype, iterator and ranged based loop makes the code look clean
