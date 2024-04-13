#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &rank, int m, int mid)
{
    int cookNum = 0;
    int dishNum = 1;
    int timetook = 0;
    for (int i = 1; i <= m; i++)
    {
        if (timetook + rank[cookNum] * dishNum <= mid)
        {
            timetook += rank[cookNum] * dishNum;
            dishNum++;
        }
        else
        {
            cookNum++;
            if (cookNum >= rank.size() || rank[cookNum] > mid)
                return false;
            timetook = rank[cookNum];
            dishNum = 2;
        }
    }
    return true;
}

int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(), rank.end());
    int ans = -1;
    int n = rank.size();
    int s = 0;
    int e = 0;
    for (int i = 1; i <= m; i++)
        e += rank[n - 1] * i;
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (isPossible(rank, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

// https://www.codingninjas.com/studio/problems/cooking-ninjas_1164174
