#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    return primes;
}

vector<int> segmentedSieve(int L, int R)
{
    // Precompute primes upto sqrt(R) as base
    vector<int> basePrimes = sieve(floor(sqrt(R)));
    vector<bool> rangeIsPrime(R - L + 1, true);

    // Mark non-primes in [L, R] using base primes
    for (int p : basePrimes)
    {
        // first multiple of p inside range
        int start = max(p * p, L + (p - L % p) % p);
        for (int i = start; i <= R; i += p)
            rangeIsPrime[i - L] = false;
    }

    // Return remaining true indices as primes
    vector<int> rangePrimes;
    for (int i = 0; i <= R - L; i++)
        if (rangeIsPrime[i])
            rangePrimes.push_back(L + i);
    return rangePrimes;
}

int main()
{
    for (int i : segmentedSieve(20, 30))
        cout << i << " ";
    cout << "\n";
    return 0;
}
