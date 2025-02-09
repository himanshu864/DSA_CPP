#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int, int>
#define vii vector<pii>
#define vvii vector<vii>

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ppb pop_back
#define mn(a, b, c) min({a, b, c})
#define mx(a, b, c) max({a, b, c})

void _print(vi &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

const int mod = 1e9 + 7;
ll mod_add(ll a, ll b) { return (a % mod + b % mod) % mod; }
ll mod_sub(ll a, ll b) { return ((a - b) % mod + mod) % mod; }
ll mod_mul(ll a, ll b) { return (a % mod * b % mod) % mod; }
ll mod_pow(ll base, ll exp)
{
    ll res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
ll mod_inv(ll a) { return mod_pow(a, mod - 2); }

int main()
{
    vi arr = {1, 2, 35, 32};
    sort(all(arr));
    _print(arr);
    return 0;
}
