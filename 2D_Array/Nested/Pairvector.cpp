#include <iostream>
#include <vector>
using namespace std;

void PrintVecPair(vector<pair<int, int>> &v)
{
    int n = v.size();
    cout << "Size: " << n << endl;
    for (int i = 0; i < n; i++)
        cout << v[i].first << " " << v[i].second << endl;
}

int main()
{
    pair<int, string> p = {2, "malik"};
    cout << p.first << " " << p.second << endl;

    p = make_pair(3, "hello");
    cout << p.first << " " << p.second << endl;

    p.first = 1;
    p.second = "himanshu";
    cout << p.first << " " << p.second << endl;

    // vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>> v;
    int n;
    cout << "Enter no. of pairs<int,int>: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter first and second: ";
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    PrintVecPair(v);
    return 0;
}
