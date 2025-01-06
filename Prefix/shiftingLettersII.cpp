#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> partial(n + 1);
        for (vector<int> shift : shifts)
        {
            int l = shift[0];
            int r = shift[1];
            int d = shift[2] == 1 ? 1 : -1;
            partial[l] += d;
            partial[r + 1] -= d;
        }

        // line sweep
        int prefix = 0;
        for (int i = 0; i < n; i++)
        {
            prefix += partial[i];
            prefix %= 26;
            int ord = s[i] - 'a';
            ord += prefix;
            ord = (ord % 26 + 26) % 26;
            s[i] = 'a' + ord;
        }
        return s;
    }
};

int main()
{
    int n = 4;
    cout << n << '\n';
    return 0;
}

// https://leetcode.com/problems/shifting-letters-ii/
