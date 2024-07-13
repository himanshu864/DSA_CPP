#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Observations:
- At no point there could be robot with zero or negative health. Since lowest 1 and 1 would collide to disappear
- Since same speed, exact position of robots don't matter.
- Collision will only happen if first robot is moving to right and second to left
- Use stack calc surviving robots while iterating and resolving collisions one robot at a time
*/

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        // Map positions and health together for sorting
        // Could use original position vector to sort surviving robots back to given order
        // We're using +ve HP for right direction and -ve for left
        vector<pair<int, int>> phd; // <position, health>
        for (int i = 0; i < positions.size(); i++)
            phd.push_back(
                {positions[i], healths[i] * (directions[i] == 'R' ? 1 : -1)});

        // Sort robots based on position
        sort(phd.begin(), phd.end());

        // Collision Handling
        stack<pair<int, int>> st; // <position, health>
        for (auto x : phd)
        {
            // Collision will happen if prev robot moving right, while current left
            if (st.size() && st.top().second > 0 && x.second < 0)
            {
                // Current robot x could destroy multiple robots that are moving right
                // Keep decreasing x's health, popping robots while x is stronger
                while (st.size() && st.top().second > 0 && -x.second > st.top().second)
                {
                    x.second++;
                    st.pop();
                }

                // After resolving possible collision
                // If curr robo has less health, prev robo destroys it
                if (st.size() && st.top().second > 0 && x.second * -1 < st.top().second)
                    st.top().second--;
                // If both robots have same health, both boom
                else if (st.size() && x.second * -1 == st.top().second)
                    st.pop();
                // Else if current robot survives collision, it's added to stack
                else
                    st.push(x);
            }
            // If no collision, simply add robo to stack
            else
                st.push(x);
        }

        // Map surviving robots final health to position
        unordered_map<int, int> hashmap;
        while (st.size())
        {
            hashmap[st.top().first] = abs(st.top().second);
            st.pop();
        }

        // And construct final answer in original position order
        vector<int> ans;
        for (auto p : positions)
            if (hashmap.count(p))
                ans.push_back(hashmap[p]);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> positions = {34, 50, 42, 2};
    vector<int> healths = {6, 27, 17, 38};
    string directions = "LLRR";

    for (int i : sol.survivedRobotsHealths(positions, healths, directions))
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/robot-collisions/description/
