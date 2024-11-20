#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int ans = 0;
        // instead of trying to find the minimum prefix and suffix with at least k of all three chars
        // try to maximize a subarray without which the array will still have at least k of all three chars
        int ta = 0, tb = 0, tc = 0;
        for (char c : s)
        {
            if (c == 'a')
                ta++;
            else if (c == 'b')
                tb++;
            else
                tc++;
        }

        // not possible
        if (ta < k || tb < k || tc < k)
            return -1;

        int a = 0, b = 0, c = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'a')
                a++;
            else if (s[j] == 'b')
                b++;
            else
                c++;

            while (ta - a < k || tb - b < k || tc - c < k)
            {
                if (s[i] == 'a')
                    a--;
                else if (s[i] == 'b')
                    b--;
                else
                    c--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return s.size() - ans;
    }
};

int main()
{
    Solution sol;
    string s = "aabaaaacaabc";
    int k = 2;
    cout << sol.takeCharacters(s, k) << endl;
    return 0;
}

// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
