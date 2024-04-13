#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans;
    for (int i = n; i > 0; i /= 10)
        ans.push_back(i % 10);

    for (int m = 1; m < n; m++)
    {
        int carry = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            int digit = ans[i] * m + carry;
            ans[i] = digit % 10;
            carry = digit / 10;
        }
        while (carry > 0)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string calculateFactorial(int n)
{
    string ans = to_string(n);
    reverse(ans.begin(), ans.end());
    for (int i = 2; i < n; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            long long temp = (ans[j] - '0') * i + carry;
            ans[j] = temp % 10 + '0';
            carry = temp / 10;
        }
        while (carry)
        {
            ans += (carry % 10) + '0';
            carry /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i : factorial(n))
        cout << i;
    return 0;
}
