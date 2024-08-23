#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int gcd(int a, int b)
    {
        a = abs(a);
        int ans = 1;
        for (int i = 2; i <= min(a, b); i++)
        {
            while (a % i == 0 && b % i == 0)
            {
                a /= i;
                b /= i;
                ans *= i;
            }
        }
        return ans;
    }

public:
    string fractionAddition(string expression)
    {
        int an = 0, ad = 1;
        int bn = 0, bd = 1;

        // add + at start if first num positive
        if (expression[0] != '-')
            expression = "+" + expression;
        // add any sign at end to calc last factor
        expression += "+";

        bool num = true;
        bool positive = true;
        for (char c : expression)
        {
            if (c == '+' || c == '-')
            {
                // solve
                an = (an * bd) + (!positive ? -1 : 1) * (bn * ad);
                ad *= bd;

                // in case of zero
                if (an == 0)
                    ad = 1;

                // cut nemo and deno
                int x = gcd(an, ad);
                an /= x;
                ad /= x;

                // reset for next factor
                bn = 0;
                bd = 0;
                num = true;
                positive = c == '+';
            }
            else if (c == '/')
                num = false;
            else
            {
                if (num)
                    bn = bn * 10 + (c - '0');
                else
                {
                    if (!positive)
                    {
                        bn *= -1;
                        positive = true;
                    }
                    bd = bd * 10 + (c - '0');
                }
            }
        }
        return to_string(an) + '/' + to_string(ad);
    }
};

int main()
{
    Solution sol;
    // string expression = "1/3-1/2";
    // string expression = "1/2-1/2";
    // string expression = "1/2+1/2";
    // string expression = "-1/2+1/3";
    // string expression = "7/3+5/2-3/10";
    string expression = "-1/4-4/5-1/4";

    cout << sol.fractionAddition(expression) << endl;
    return 0;
}

// https://leetcode.com/problems/fraction-addition-and-subtraction/
