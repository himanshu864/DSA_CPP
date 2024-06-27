#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &e)
    {
        return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
    }
};

int main()
{
    int n = 4;
    cout << n << endl;
    return 0;
}
