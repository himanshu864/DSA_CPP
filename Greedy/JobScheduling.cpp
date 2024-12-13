#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Job
{
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

// Striver Nigga correct shit solution
class Solution
{
public:
    // keep scheduling jobs greedily based on higer profit
    vector<int> JobScheduling(Job jobs[], int n)
    {
        int lastDay = 0;
        vector<pair<int, int>> tasks;
        for (int i = 0; i < n; i++)
        {
            tasks.push_back({jobs[i].profit, jobs[i].deadline});
            lastDay = max(lastDay, jobs[i].deadline);
        }
        sort(tasks.begin(), tasks.end(), greater());

        int jobsDone = 0;
        int totalProfit = 0;
        vector<int> schedule(lastDay + 1, -1);
        for (auto job : tasks)
        {
            int profit = job.first, deadline = job.second;
            while (deadline > 0 && schedule[deadline] != -1)
                deadline--;

            if (deadline)
            {
                schedule[deadline] = 1;
                jobsDone++;
                totalProfit += profit;
            }
        }
        return {jobsDone, totalProfit};
    }
};

// My failed efforts. idk what's wrong
class Solution2
{
public:
    vector<int> JobScheduling(Job jobs[], int n)
    {
        vector<pair<int, int>> tasks;
        for (int i = 0; i < n; i++)
            tasks.push_back({jobs[i].deadline, jobs[i].profit});

        // perform tasks reversed sorted deadlines and maximum profit first
        sort(tasks.begin(), tasks.end(), [&](pair<int, int> a, pair<int, int> b)
             {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first; });

        priority_queue<int> jobsDue;
        int jobsDone = 0;
        int totalProfit = 0;
        int day = tasks[0].first;

        for (auto job : tasks)
        {
            int deadline = job.first;
            int profit = job.second;

            // if deadline past
            if (deadline > day)
            {
                jobsDue.push(profit);
                continue;
            }

            // if deadline to come, keep finishing pending jobs
            while (!jobsDue.empty() && day > deadline)
            {
                totalProfit += jobsDue.top();
                jobsDue.pop();
                jobsDone++;
                day--;
            }

            // on deadline, perform the highest profit job
            jobsDue.push(profit);
            totalProfit += jobsDue.top();
            jobsDue.pop();
            jobsDone++;
            day = deadline - 1;

            if (day == 0)
                break;
        }

        return {jobsDone, totalProfit};
    }
};

int main()
{
    Solution sol;
    Job jobs[7];
    int n = 7;
    vector<vector<int>> jbs = {
        {1, 1, 50},
        {2, 2, 90},
        {3, 3, 10},
        {4, 4, 80},
        {5, 4, 70},
        {6, 4, 100},
        {7, 10, 10},
    };
    for (int i = 0; i < n; i++)
    {
        jobs[i].id = jbs[i][0];
        jobs[i].deadline = jbs[i][1];
        jobs[i].profit = jbs[i][2];
    }
    vector<int> ans = sol.JobScheduling(jobs, n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
