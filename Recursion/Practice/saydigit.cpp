#include <bits/stdc++.h>
using namespace std;

void saydigit(long long int n, string word[])
{
    if (n == 0)
        return;
    saydigit(n / 10, word);
    cout << word[n % 10] << " ";
}

string saymyname(long long int n, string word[])
{
    string ans = "";
    for (long long int i = n; i > 0; i /= 10)
        ans = word[i % 10] + " " + ans;
    return ans;
}

int main()
{
    long long int n;
    cout << "Enter a number: ";
    cin >> n;

    string word[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << saymyname(n, word) << endl;
    saydigit(n, word);
    return 0;
}
