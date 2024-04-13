#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 2, 2, 3, 1, 5};
    cout << "Given array: " << endl;
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    // pre-computer
    unordered_map<int, int> hashmap_uh;
    for (int i : nums)
        hashmap_uh[i]++;

    // iterating in the map
    cout << "How values are stored in hashmap_uh: " << endl;
    for (auto i : hashmap_uh)
        cout << i.first << "->" << i.second << endl;

    // fetch
    cout << "Fetching occurence of number 0 to 6: " << endl;
    for (int i = 0; i < 6; i++)
        cout << i << " appears " << hashmap_uh[i] << " times" << endl;

    return 0;
}

// observations:
// no need to check or push if exists or not before incrementing
// if doesn't exist key, value initialized as 0
// can traverse using iterator

// map<key, value> are sorted, T.C : O(logN) , can store any data structure/type. int/char/string/pair, etc
// unordered<> map not sorted, T.C : O(1) : avg and best, but rarely O(N) for worst
// can only store int/char/string/double, not pair<int,int>.
// in division method, if all keys hashed at same linked list, might collide and worst case tc
