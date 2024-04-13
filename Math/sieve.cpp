#include <iostream>
#include <vector>
using namespace std;

// Sieve of Eratosthenes
// Time Complexity: O(nlog(log(n)))
// Space Complexity: O(n)

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

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> ans = sieve(n);
    for (int i : ans)
        cout << i << " ";
    return 0;
}
