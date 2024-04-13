#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> v;
    int N;
    cout << "Enter N: ";
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // vector<int> temp;
        v.push_back(vector<int>());
        int n;
        cout << "Enter n and elements: ";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            // temp.push_back(x);
            v[i].push_back(x);
        }
        // v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
