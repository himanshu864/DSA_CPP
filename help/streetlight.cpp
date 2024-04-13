#include <bits/stdc++.h>
using namespace std;

int LightUptheStreet(int n, int m, int k, vector<int> Checkpoints)
{
    int max_till_now = 0, last_range = 0;
    int ans = 0;
    for (int i : Checkpoints)
    {
        if (i - k - 1 > last_range)
        {
            if (i - k - 1 > max_till_now)
            {
                ans = -1;
                break;
            }
            ans++;
            last_range = max_till_now;
        }
        max_till_now = i + k;
    }
    if (last_range < n)
    {
        if (max_till_now < n)
            ans = -1;
        else
            ans++;
    }
    return ans;
}

// https://www.codingninjas.com/studio/problems/street-lights_2245469
