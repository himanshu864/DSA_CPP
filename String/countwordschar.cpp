#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// newer ig
int countCharacters(vector<string> &words, string chars)
{
    int sum = 0;

    int data[26] = {0};
    for (int i = 0; i < chars.size(); i++)
        data[chars[i] - 'a']++;

    for (int i = 0; i < words.size(); i++)
    {
        int freq[26] = {0};
        for (int j = 0; j < words[i].size(); j++)
            freq[words[i][j] - 'a']++;

        bool flag = true;
        for (int x = 0; x < 26; x++)
            if (freq[x] > data[x])
                flag = false;

        if (flag)
            sum += words[i].size();
    }
    return sum;
}

// int countCharacters2(vector<string> &words, string chars)
// {
//     int sum = 0;
//     for (int i = 0; i < words.size(); i++)
//     {
//         int exist[128] = {0};
//         for (int x = 0; x < chars.length(); x++)
//             exist[chars[x]]++;

//         sum += words[i].length();
//         for (int j = 0; j < words[i].length(); j++)
//         {
//             if (exist[words[i][j]] == 0)
//             {
//                 sum -= words[i].length();
//                 break;
//             }
//             else
//                 exist[words[i][j]]--;
//         }
//     }
//     return sum;
// }

int main()
{
    // string chars = "attack";
    string chars = "hact";
    vector<string> words = {"cat", "bt", "hat", "tree"};
    cout << countCharacters(words, chars);
    return 0;
}

// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
