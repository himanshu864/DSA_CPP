#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int m1[256] = {0};
    int m2[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    string s = "aaabbb";
    string t = "aabbab";
    cout << ((isIsomorphic(s, t)) ? "True" : "False");
    return 0;
}

// https://leetcode.com/problems/isomorphic-strings/
