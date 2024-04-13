#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m = {{1, "Himanshu"}};

    m[2] = "Babbar";
    m[2] = "Love"; // same key, can't have different value, love replaced babbar
    m[6] = "Malik";
    m.insert({4, "Angel"});
    m.insert({5, "Himanshu"}); // different keys can have same value

    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    cout << " > Is 6 present: " << m.count(6) << endl;

    // 1. erase using key
    // m.erase(2);
    // 2. erase using iterator
    map<int, string>::iterator itr = m.begin();
    itr++;
    itr++;
    m.erase(itr);
    cout << " > Erasing key 4 or 3rd iteration: " << endl;
    for (auto i : m)
        cout << i.first << " " << i.second << endl;

    cout << " > Printing 5 to end: " << endl;
    auto it = m.find(5);
    for (auto i = it; i != m.end(); i++)
        cout << i->first << " " << i->second << endl;
    // cout << (*i).first << " " << (*i).second << endl;

    return 0;
}

// ordered map: sorted;
// key based
// one key can't point to multiple values
// though multiple values can have same key
// insert, erase, find, count: T.C: O(logN)
// in case of ordered map, search is O(logN), generally it's O(1)
