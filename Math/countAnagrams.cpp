#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7;
    vector<int> fact, invFact;

    int modExp(int a, int b)
    {
        if (b == 0)
            return 1;
        if (b & 1)
            return (a * 1LL * modExp(a, b - 1)) % mod;
        int x = modExp(a, b >> 1);
        return (x * 1LL * x) % mod;
    }
    int inverse(int a)
    {
        return modExp(a, mod - 2);
    }

    void precompute(int n)
    {
        fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = (i * 1LL * fact[i - 1]) % mod;

        invFact.resize(n + 1);
        invFact[n] = inverse(fact[n]);
        for (int i = n - 1; i >= 0; i--)
            invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % mod;
    }

public:
    int countAnagrams(string s)
    {
        int n = s.size();
        precompute(n); // factorial and inverse

        // convert string into words
        vector<string> words;
        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (i < n && s[i] != ' ')
                word += s[i++];
            words.push_back(word);
        }

        // permute anagrams
        int ans = 1;
        for (string word : words)
        {
            vector<int> freq(26);
            for (char c : word)
                freq[c - 'a']++;

            ans = (ans * 1LL * fact[word.size()]) % mod;
            for (int i : freq)
                if (i > 1)
                    ans = (ans * 1LL * invFact[i]) % mod;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "hot too";
    cout << sol.countAnagrams(s) << "\n";
    return 0;
}

// https://leetcode.com/problems/count-anagrams/
