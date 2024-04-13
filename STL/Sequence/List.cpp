#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l = {5, 6, 7};

    l.pop_front();
    l.push_back(9);
    l.push_front(3);
    l.push_front(4);
    l.erase(l.begin());

    for (int i : l)
        cout << i << " ";
    cout << endl;
    cout << "size: " << l.size() << endl;

    return 0;
}

// List c++ STL: doubly-linked list
