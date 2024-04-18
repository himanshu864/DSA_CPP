#include <iostream>
#include <algorithm>
using namespace std;

// implicit reference lambda functions
class Solution
{
public:
    string customSortString(string order, string s)
    {
        sort(s.begin(), s.end(),
             [&](char a, char b)
             { return order.find(a) < order.find(b); });
        return s;
    }
};

int main()
{
    Solution sol;
    string order = "bcafg";
    string s = "abcd";
    cout << sol.customSortString(order, s) << endl;

    // lambda functions
    // syntax:
    // [lambda introducer](parameters list){function and return}(passing value)
    cout << [](int x)
    { return x + 2; }(2) << endl;

    cout << [](int x, int y)
    { return x + y; }(5, 7) << endl;

    auto sum = [](int x, int y)
    { return x + y; };
    cout << sum(3, 6) << endl;

    return 0;
}

// https://leetcode.com/problems/custom-sort-string/
