#include <bits/stdc++.h>
using namespace std;

int minimumNet(int n, int k, vector<bool> fish)
{
    int ans = n + 1;
    int count = 0;
    queue<int> spot;
    for (int i = 0; i < n; i++)
    {
        if (fish[i])
        {
            spot.push(i);
            count++;
        }
        if (count == k)
        {
            ans = min(ans, i - spot.front() + 1);
            spot.pop();
            count--;
        }
    }
    if (ans == n + 1)
        return -1;
    return ans;
}

int main()
{
    vector<bool> fish = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1};
    int n = fish.size();
    int k = 3;
    cout << minimumNet(n, k, fish) << endl;
    return 0;
}

// https://www.codingninjas.com/studio/contests/love-babbar-contest-3/3743976/problems/16650
