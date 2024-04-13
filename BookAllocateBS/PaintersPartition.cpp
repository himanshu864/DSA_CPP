#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid)
{
    int n = boards.size();
    int PainterCount = 1;
    int totaltime = 0;
    for (int i = 0; i < n; i++)
    {
        if (boards[i] + totaltime <= mid)
            totaltime += boards[i];
        else
        {
            PainterCount++;
            if (PainterCount > k || boards[i] > mid)
                return false;
            totaltime = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int ans = -1;
    int n = boards.size();
    int s = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
        e += boards[i];
    while (s <= e)
    {
        int mid = (s + (e - s) / 2);
        if (isPossible(boards, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557