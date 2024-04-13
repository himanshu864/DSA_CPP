#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minimizeStringValue(string s)
    {
        int q = 0;
        vector<int> freq(26, 0);
        for (char c : s)
        {
            if (c == '?')
                q++;
            else
                freq[c - 'a']++;
        }

        string genius = "";
        while (q--)
        {
            int minf = 100000;
            char minc = 125;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] < minf)
                {
                    minf = freq[i];
                    minc = i + 'a';
                }
            }
            freq[minc - 'a']++;
            genius += minc;
        }
        sort(genius.begin(), genius.end());

        for (int i = 0, x = 0; i < s.size(); i++)
            if (s[i] == '?')
                s[i] = genius[x++];
        return s;
    }
};

int main()
{
    Solution sol;
    string s = "a?a?";
    cout << sol.minimizeStringValue(s) << endl;
    return 0;
}
