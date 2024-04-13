#include <iostream>
using namespace std;

void subseqstr(string s)
{
    int n = s.size();
    for (int i = 0; i < (1 << n); i++) // 1 << n is same as 2^n
    {
        string temp = "";
        for (int j = 0; j < n; j++)
            if (i & (1 << (n - j - 1))) // to check if that char's has a set bit
                temp += s[j];
        cout << temp << endl;
    }
}

int main()
{
    string s = "abc";
    subseqstr(s);
    return 0;
}

// a,b,c are at index 0, 1, 2

// there will be (2^n - 1) subsequences
// 0 0 0 - ""
// 0 0 1 - "c"
// 0 1 0 - "b"
// 0 1 1 - "bc"
// 1 0 0 - "a"
// 1 0 1 - "ac"
// 1 1 0 - "ab"
// 1 1 1 - "abc"

// create a mask for index and &(AND) operation to check if that bit is set

// https://leetcode.com/problems/subsets/
