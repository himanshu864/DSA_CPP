#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    // while (s.size() && s.find(part) < s.size())
    while (s.size() && s.find(part) != string::npos)
        s.erase(s.find(part), part.size());
    return s;
}

string removeOccurrence(string s, string part)
{
    size_t pos = s.find(part);
    while (pos != string::npos)
    {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part);
    return 0;
}

// size_t is used for index/positions
// string::npos is to check if index/position exists within the string or not
// can study erase/find/insert/replace at strings cplusplus website. pretty similar to vectors

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
