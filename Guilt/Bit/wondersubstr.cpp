#include <iostream>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long cnt[1024] = {1}, mask = 0, res = 0;
        for (auto ch : word)
        {
            mask ^= 1 << (ch - 'a');
            res += cnt[mask];
            for (auto n = 0; n < 10; ++n)
                res += cnt[mask ^ (1 << n)];
            ++cnt[mask];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string word = "aabb";
    cout << sol.wonderfulSubstrings(word) << endl;
    return 0;
}
