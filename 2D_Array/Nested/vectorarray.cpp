#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cout << "Enter no. of vectors: ";
    cin >> N;

    vector<int> varr[N];

    for (int i = 0; i < N; i++)
    {
        int n;
        cout << "Enter size of vector and elements: ";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            varr[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < varr[i].size(); j++)
            cout << varr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
