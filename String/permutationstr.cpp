#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    vector<int> cur(26), goal(26);
    for (char c : s1)
        goal[c - 'a']++;

    for (int i = 0; i < s2.size(); i++)
    {
        cur[s2[i] - 'a']++;
        if (i >= s1.size())
            cur[s2[i - s1.size()] - 'a']--;
        if (goal == cur)
            return true;
    }
    return false;
}

int main()
{
    string s1 = "abc";
    string s2 = "dbnabcagc";
    cout << checkInclusion(s1, s2);
    return 0;
}

/*
bool checkplz(string s1, string s2)
{
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}
bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    for (int i = 0; i <= n2 - n1; i++)
    {
        if (checkplz(s1, s2.substr(i, n1)))
            return true;
    }
    return false;
}
*/
