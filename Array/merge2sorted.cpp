#include <bits/stdc++.h>
using namespace std;

// merges two non-decreasingly sorted arrays, and removes all duplicates
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else
        {
            if (ans.empty() || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        if (ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        if (ans.empty() || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 3};
    vector<int> b = {2, 2, 4};
    vector<int> res = sortedArray(a, b);
    for (int i : res)
        cout << i << " ";
    return 0;
}
