#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &piles, int h, int mid)
{
    int time = 0;
    for (int pile : piles)
    {
        time += ((pile - 1) / mid) + 1;
        if (time > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int s = 1;
    int e = *max_element(piles.begin(), piles.end());
    int k = e;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(piles, h, mid))
        {
            k = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return k;
}

// https://leetcode.com/problems/koko-eating-bananas/
