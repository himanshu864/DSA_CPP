#include <iostream>
#include <vector>
using namespace std;

void recursion(string digits, string temp, vector<string> pad, vector<string> &ans, int i)
{
    if (i == digits.size())
    {
        if (temp != "")
            ans.push_back(temp);
        return;
    }
    int num = digits[i] - '2';
    for (char x : pad[num])
        recursion(digits, temp + x, pad, ans, i + 1);
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string temp = "";
    vector<string> pad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    recursion(digits, temp, pad, ans, 0);
    return ans;
}

int main()
{
    string digits = "92";
    for (string i : letterCombinations(digits))
        cout << i << endl;
    return 0;
}

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
