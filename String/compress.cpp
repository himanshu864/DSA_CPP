#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// I'm better
string getCompressedBitch(string str)
{
    string ans = "";
    ans += str[0];
    int freq = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
            freq++;
        else
        {
            if (freq > 1)
            {
                ans += to_string(freq);
                freq = 1;
            }
            ans += str[i];
        }
    }
    if (freq > 1)
        ans += to_string(freq);
    return ans;
}

string getCompressedString(string &input)
{
    string output = "";
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        int freq = 1;
        while (input[i] == input[i + 1])
        {
            freq++;
            i++;
        }
        if (freq == 1)
            output += input[i];
        else
            output += (input[i] + to_string(freq));
    }
    return output;
}

void NotStringButChar(char input[])
{
    for (int i = 0; i < strlen(input); i++)
    {
        int count = 1;
        int j = i + 1;
        while (input[j] == input[i])
        {
            count++;
            j++;
        }
        cout << input[i];
        if (count != 1)
        {
            cout << count;
            i = j - 1;
        }
    }
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}