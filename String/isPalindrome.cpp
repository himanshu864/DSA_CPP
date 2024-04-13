#include <bits/stdc++.h>
using namespace std;

char boink(char x) // tolower(char)
{
    if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
        return x;
    else
        return (x - 'A' + 'a');
}

bool checkimposter(char x) // isalnum(char);
{
    if (x >= 'a' && x <= 'z')
        return false;
    else if (x >= 'A' && x <= 'Z')
        return false;
    else if (x >= '0' && x <= '9')
        return false;
    else
        return true;
}

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        if (checkimposter(s[i]))
            i++;
        else if (checkimposter(s[j]))
            j--;
        else if (boink(s[i]) == boink(s[j]))
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

/*
bool checkPalindrome(string s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (isalnum(s[i]) == false)
            i++;
        else if (isalnum(s[j]) == false)
            j--;
        else if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }
    return true;
}
*/

int main()
{
    string word = "race @#$69 6e car";
    cout << isPalindrome(word);
    return 0;
}

// https://leetcode.com/problems/valid-palindrome/
