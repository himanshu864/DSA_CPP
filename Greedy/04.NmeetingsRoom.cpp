#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxMeetings(vector<int> start, vector<int> end)
    {
        // store meetings based on ending time, based on intuition
        vector<pair<int, int>> meet;
        for (int i = 0; i < start.size(); i++)
            meet.push_back({start[i], end[i]});

        sort(meet.begin(), meet.end(), [&](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });

        // and count no. of non-overlapping meetings
        int ans = 0, ending = -1;
        for (auto x : meet)
            if (x.first > ending)
            {
                ending = x.second;
                ans++;
            }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << sol.maxMeetings(start, end) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
