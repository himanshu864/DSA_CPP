#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactorials(int n)
{
    vector<int> ans;
    for (int i = 2, x = sqrt(n); i <= x; i++)
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    return ans;
}

int main()
{
    for (int i : primeFactorials(420))
        cout << i << " ";
    cout << '\n';
    return 0;
}
