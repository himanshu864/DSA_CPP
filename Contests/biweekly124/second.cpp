#include <iostream>
#include <vector>
using namespace std;

string lastNonEmptyString(string s)
{
    string ans = "";
    int freq[26] = {0};
    for (char c : s)
        freq[c - 'a']++;

    int max = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > max)
            max = freq[i];

    vector<bool> temp(26, false);
    for (int i = 0; i < 26; i++)
        if (freq[i] == max)
            temp[i] = true;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (temp[s[i] - 'a'])
        {
            ans = s[i] + ans;
            temp[s[i] - 'a'] = false;
        }
    }
    return ans;
}

int main()
{
    string s = "aabcbbca";
    cout << lastNonEmptyString(s);
    return 0;
}
