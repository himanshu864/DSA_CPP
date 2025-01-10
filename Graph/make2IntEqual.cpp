#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int n, int m)
    {
        string F = to_string(n);

        // pre-compute digits primes using sieve
        int len = F.size();
        int maxi = pow(10, len);
        vector<bool> isPrime(maxi, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < maxi; i++)
            if (isPrime[i])
                for (int j = i * i; j < maxi; j += i)
                    isPrime[j] = false;

        // base case
        if (isPrime[n] || isPrime[m])
            return -1;

        // Dijkstra {sum, string}
        vector<bool> visited(pow(10, len), false);
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        q.push({n, F});
        while (q.size())
        {
            auto [sum, s] = q.top();
            q.pop();

            int c = stoi(s);
            if (c == m)
                return sum;

            if (isPrime[c] || visited[c])
                continue;
            visited[c] = true;

            for (int i = 0; i < len; i++)
            {
                if (s[i] != '9') // +
                {
                    s[i]++;
                    int x = stoi(s);
                    if (!isPrime[x] || !visited[x])
                        q.push({sum + x, s});
                    s[i]--;
                }
                if (s[i] != '0' && !(i == 0 && s[i] == '1')) // -
                {
                    s[i]--;
                    int x = stoi(s);
                    if (!isPrime[x] || !visited[x])
                        q.push({sum + x, s});
                    s[i]++;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.minOperations(10, 12) << endl;
    return 0;
}

// https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/
