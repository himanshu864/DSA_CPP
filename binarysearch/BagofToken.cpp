#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int ans = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                ans = max(ans, score);
                i++;
            }
            else if (score > 0)
            {
                power += tokens[j];
                score--;
                j--;
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    cout << sol.bagOfTokensScore(tokens, power) << endl;
    return 0;
}

// https://leetcode.com/problems/bag-of-tokens/
