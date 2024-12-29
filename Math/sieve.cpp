#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
// Time Complexity: O(nlog(log(n)))
// Space Complexity: O(n)
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

int main()
{
    for (int i : sieve(60))
        cout << i << " ";
    cout << '\n';
    return 0;
}
