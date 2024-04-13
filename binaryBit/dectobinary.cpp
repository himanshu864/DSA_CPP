#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Approach 1: Divide by 2 and reverse the remainder
    int ans = 0;
    for (int i = n, j = 0; i != 0; i /= 2)
    {
        ans += (i % 2) * pow(10, j++);
    }
    cout << ans << endl;

    // Approach 2: Keep Right shifting and reverse the last bit (i&1)
    // int ans2 = 0;
    // for (int i = n, j = 0; i != 0; i = i >> 1)
    // {
    //     ans2 += (i & 1) * pow(10, j++);
    // }
    // cout << ans2 << endl;

    // Approach 3: To print the entire 32 bits.
    // ChatGPT to the rescue, just do (n >> i) to get print first bit, last.
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        cout << bit;
    }
    cout << endl;

    return 0;
}

// Note: if (i & 1) == 1;  means i is an odd number, because last bit is 1
