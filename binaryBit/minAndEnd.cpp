#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    /*
    arr[0] = 0100 = x
    arr[1] = 0101
    arr[2] = 0110
    arr[3] = 0111
    arr[4] = 1100

    set bit remains the same as x and zeros keep incrementing one by one
    Hence, or arr[n - 1] fill zeros of x with binary values of n - 1
    */
    vector<int> reverseBinary(int n)
    {
        vector<int> ans;
        while (n)
        {
            ans.push_back(n % 2);
            n /= 2;
        }
        return ans;
    }

public:
    long long minEnd(int n, int x)
    {
        vector<int> binX = reverseBinary(x);
        vector<int> binN = reverseBinary(n - 1);

        // since reversed, easy fill from left to right
        for (int i = 0, j = 0; j < binN.size(); i++, j++)
        {
            while (i < binX.size() && binX[i] == 1)
                i++;

            if (i < binX.size())
                binX[i] = binN[j];
            else
                binX.push_back(binN[j]);
        }

        // convert into long long
        long long ans = 0, bit = 0;
        for (long long b : binX)
            ans += (1 << bit++) * b;
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 3;
    int x = 4;
    cout << sol.minEnd(n, x) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-array-end/
