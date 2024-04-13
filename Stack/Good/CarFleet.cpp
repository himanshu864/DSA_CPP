#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// 2nd Try bitch!!
// 7:44PM DTU Library 1/04/24. Love the suffering and grind

// basically use target, position and speed to find the exact time it will take each car to reach target
// and sort them according to their position
// we can do pretty conveniently using ordered maps, as each position is given to be unique
// now we easily merge all car fleets using a decreasing monotonic stack

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        map<int, double> time;
        for (int i = 0; i < position.size(); i++)
            time[position[i]] = double(target - position[i]) / double(speed[i]);

        stack<double> st;
        for (auto i : time)
        {
            while (st.size() && i.second >= st.top())
                st.pop();
            st.push(i.second);
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;
    cout << sol.carFleet(target, position, speed) << endl;
    return 0;
}

// https://leetcode.com/problems/car-fleet/
