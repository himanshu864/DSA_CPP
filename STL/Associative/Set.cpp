#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    // set<int> s = {4, 4, 1, 2, 5, 3};
    // set<int, greater<int>> ulta = {4, 1, 2, 5, 3} --> 5, 4, 3, 2, 1

    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(5);
    s.insert(3);
    s.insert(3); // T.C: O(logN)

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    // set<int>::iterator it = s.begin();
    // it++;
    // s.erase(it);
    s.erase(2);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << "Is 3 present: " << s.count(3) << endl;

    set<int>::iterator it = s.find(3);

    for (auto i = it; i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;
}
