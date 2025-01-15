#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // return xor of 1 to n
    int xorn(int n)
    {
        int r = (n + 1) % 4;
        if (r == 0)
            return 0;
        else if (r == 1)
            return n;
        else if (r == 2)
            return 1;
        return n + 1;
    }

public:
    int findXOR(int l, int r)
    {
        return xorn(r) ^ xorn(l - 1);
    }
};

int main()
{
    Solution sol;
    cout << sol.findXOR(4, 8) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
