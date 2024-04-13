#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseWordAns(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            int j = i;
            while (j < s.size() && s[j] != ' ')
                j++;

            if (ans != "")
                ans += ' ';

            string word = s.substr(i, j - i);
            reverse(word.begin(), word.end());
            ans += word;
            i = j - 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// inplace with trimming
string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            if (x != 0)
                s[x++] = ' ';

            int j = i;
            while (j < s.size() && s[j] != ' ')
                s[x++] = s[j++];

            reverse(s.begin() + x - (j - i), s.begin() + x);
            i = j;
        }
    }
    s.erase(s.begin() + x, s.end());
    return s;
}

// Time and Space Complexity: O(n), with trimming(still somehow worst idk)
string reverseWordLinear(string s)
{
    string ans = "";
    string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if (ans.empty())
                ans = word;
            else if (word.size())
                ans = word + ' ' + ans;
            word = "";
        }
    }
    if (word.size())
    {
        if (ans.empty())
            ans = word;
        else
            ans = word + ' ' + ans;
    }
    return ans;
}

int main()
{
    string s = "  my name himanshu  is aggarwal  ";
    // getline(cin, s);
    cout << reverseWords(s) << endl;
    cout << reverseWordAns(s) << endl;
    cout << reverseWordLinear(s) << endl;
    return 0;
}

// https://leetcode.com/problems/reverse-words-in-a-string/
