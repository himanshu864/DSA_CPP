#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        l--, r--; // 1-indexed

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> L(arr.begin(), arr.begin() + r + 1);
        vector<int> R(arr.begin() + l, arr.end());

        sort(L.begin(), L.end());
        sort(R.begin(), R.end());

        int lsum = accumulate(L.begin(), L.begin() + r - l + 1, 0LL);
        int rsum = accumulate(R.begin(), R.begin() + r - l + 1, 0LL);

        cout << min(lsum, rsum) << '\n';
    }
    return 0;
}

// https://codeforces.com/problemset/problem/2063/B
