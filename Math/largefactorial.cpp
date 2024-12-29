#include <bits/stdc++.h>
using namespace std;

vector<int> largerFactorial(int n)
{
    // Initialize with 1 (0! and 1!)
    vector<int> result = {1};

    // Multiply numbers from 2 to n in reverse
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < result.size(); j++)
        {
            int prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }
        // Add remaining carry as new digits
        while (carry)
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Reverse to correct order
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    for (int i : largerFactorial(20))
        cout << i;
    cout << "\n";
    return 0;
}
