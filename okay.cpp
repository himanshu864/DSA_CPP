#include <bits/stdc++.h>
using namespace std;

// i've used help for modulo becoz i was struggling
// remind me to study this bs again
int mod = 1e9 + 7;
int modmul(int a, int b)
{
    return ((long long)(a % mod) * (b % mod)) % mod;
}
int binExpo(int a, int b)
{
    if (!b)
        return 1;
    int res = binExpo(a, b / 2);
    if (b & 1)
        return modmul(a, modmul(res, res));
    else
        return modmul(res, res);
}
int modmulinv(int a)
{
    return binExpo(a, mod - 2);
}

// other than that bs, my code is fine
// i still haven't used istringsteam, fact[10001] becoz i don't undertand them.
int countAnagrams(string s)
{
    int ans = 1;

    vector<string> words;
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            words.push_back(s.substr(j, i - j));
            j = i + 1;
        }
    }
    words.push_back(s.substr(j, s.size() - j));

    for (string w : words)
    {
        for (int i = 2; i <= w.size(); i++)
            ans = modmul(ans, i);

        int freq[26] = {0};
        for (char ch : w)
        {
            freq[ch - 'a']++;
            ans = modmul(ans, modmulinv(freq[ch - 'a']));
        }
    }
    return ans;
}

signed main()
{
    string s = "hot too";
    cout << countAnagrams(s);
    return 0;
}

// https://leetcode.com/problems/count-anagrams/solutions/2947111/c-solution-math-with-explanation-each-step-in-detail/
