#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// correct answer using unordered_set and recursion
// but tle

// How does this iterative function works to find no. of distinct subsequences correctly
// There is an extra subseq. for every case, but that's prolly to handle 0 * 2 edge case
// HELPP
int func(string s)
{
    int ans = 1;
    unordered_map<char, int> m1;

    // Calculating number of distinct subsequences.
    for (char c : s)
    {
        if (m1[c] == 0)
        {
            m1[c] = ans;
            ans *= 2;
        }
        else
        {
            int temp = m1[c];
            m1[c] = ans;
            ans *= 2;
            ans -= temp;
        }
    }
    return ans;
}

string moreSubsequence(int n, int m, string a, string b)
{
    // cout << "Subseq in " << a << ":" << func(a) << endl;
    // cout << "Subseq in " << b << ":" << func(b) << endl;

    if (func(a) < func(b))
        return b;
    return a;
}

int main()
{
    // string a = "aab";
    string a = "ab";
    int n = a.size();
    // string b = "aba";
    string b = "bb";
    int m = b.size();

    cout << moreSubsequence(n, m, a, b);
    return 0;
}

// https://www.naukri.com/code360/problems/more-subsequence_8842355
