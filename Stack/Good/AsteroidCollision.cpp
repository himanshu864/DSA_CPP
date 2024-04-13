#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (int i : asteroids)
        {
            while (ans.size() && ans.back() > 0 && i < 0 && ans.back() < (-i))
                ans.pop_back();

            if (ans.size() && ans.back() > 0 && i < 0 && ans.back() == (-i))
                ans.pop_back();
            else if (ans.size() && ans.back() > 0 && i < 0 && ans.back() > (-i))
                continue;
            else
                ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> asteroids = {-1, 10, 2, -5};
    vector<int> ans = sol.asteroidCollision(asteroids);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/asteroid-collision/
