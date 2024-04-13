#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string S)
{
    string ans = "";
    for (char &c : S)
        if (ans.size() && c == ans.back())
            ans.pop_back();
        else
            ans.push_back(c);
    return ans;
}

int main()
{
    // string s = "cabbad";
    string s = "ccabddb";
    cout << removeDuplicates(s);
    return 0;
}

// basically keep popping pairs like zumba
