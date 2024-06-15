#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++)
            projects[i] = {capital[i], profits[i]};

        // sort projects by capital
        sort(projects.begin(), projects.end());

        int i = 0;
        priority_queue<int> maximizeCapital;
        // keep adding affordable projects to maxHeap, as budget increases
        // and pop curr most profitable project, atmost k times
        while (k--)
        {
            while (i < n && projects[i].first <= w)
                maximizeCapital.push(projects[i++].second);

            if (maximizeCapital.empty())
                break;

            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};

int main()
{
    Solution sol;

    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};

    cout << sol.findMaximizedCapital(k, w, profits, capital) << endl;
}

// https://leetcode.com/problems/ipo/
