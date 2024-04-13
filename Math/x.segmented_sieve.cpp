#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> isprime(n + 1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    return primes;
}

vector<int> rangepp(int l, int h)
{
    vector<int> ans;
    vector<int> primes = sieve(floor(sqrt(h)));
    vector<bool> isprime(h - l + 1, true);

    for (int p : primes)
    {
        int sm = max(p * p, (l / p) * p);
        if (sm < l)
            sm += p;
        for (int i = sm; i <= h; i += p)
            isprime[i - l] = false;
    }

    for (int i = max(2, l); i <= h; i++)
        if (isprime[i - l])
            ans.push_back(i);

    return ans;
}

int main()
{
    int l, h;
    cout << "Enter low and high: ";
    cin >> l >> h;
    vector<int> ans = rangepp(l, h);
    for (int i : ans)
        cout << i << " ";
    return 0;
}

// sm = first miltiple of primes(p) inside range
// check indexes of isprime carefully
