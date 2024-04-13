#include <bits/stdc++.h>
using namespace std;

long long threeWaySplit(int n, vector<int> arr)
{
    int ans = 0;
    int a = 0;
    int b = n - 1;
    int S1 = arr[a];
    int S3 = arr[b];
    while (a < b)
    {
        if (S1 == S3)
        {
            ans = S1;
            a++;
            b--;
            S1 += arr[a];
            S3 += arr[b];
        }
        else if (S1 > S3)
        {
            b--;
            S3 += arr[b];
        }
        else
        {
            a++;
            S1 += arr[a];
        }
    }
    return ans;
}

// https://www.codingninjas.com/studio/contests/love-babbar-contest-l/3189127/problems/15017
