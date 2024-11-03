#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    ( -> +1
    . -> 0
    ) -> -1
*/

/*
for string to be balanced, while iterating there should never be more closing than opening brackets
that's why we can cancel extra closing with *'s
but if after iteration. There are extra openings. We can't tell if string is balanced for sure
you might if after iteration, there are more star's than opening. String can be balanced.
but that's wrong. example : **(
extra *'s must come after openings, for string to be made balanced
hence must two stacks to store count and indices of *'s and ('s
after iteration, if all opening brackets that a star with index greater inside star, return true
else false
*/

// My stack greedy solution
class Solution1
{
public:
    bool checkValidString(string s)
    {
        stack<int> opening, star;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                opening.push(i);
            else if (s[i] == '*')
                star.push(i);
            else
            {
                if (opening.size())
                    opening.pop();
                else if (star.size())
                    star.pop();
                else
                    return false;
            }
        }
        while (opening.size() && star.size() && opening.top() < star.top())
        {
            opening.pop();
            star.pop();
        }
        return opening.empty();
    }
};

/*
consider all possible values of *
but instead of doing dp, carry possible range of balance
maxRange can never go negative for string to be balanced. i.e. closings aren't > openings
and after completing iteration. zero should lie in Range
since, balance can never go -ve anyways, minRange = max(0, ...)
we'll simply check if minRange == 0 at the end. i.e. openings aren't > closings
*/

// Striver Greedy Solution
class Solution2
{
public:
    bool checkValidString(string s)
    {
        int minRange = 0, maxRange = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                minRange++;
                maxRange++;
            }
            else if (c == ')')
            {
                minRange = max(0, minRange - 1);
                maxRange--;
            }
            else
            {
                minRange = max(0, minRange - 1);
                maxRange++;
            }
            if (maxRange < 0)
                return false;
        }
        return minRange == 0;
    }
};

int main()
{
    Solution2 sol;
    // string s = "()*)*()";
    string s = "*())*(";
    cout << sol.checkValidString(s) << endl;
    return 0;
}

// https://leetcode.com/problems/valid-parenthesis-string/
