#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cfloat>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K)
    {
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker : workers)
        {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K)
                qsum -= pq.top(), pq.pop();
            if (pq.size() == K)
                res = min(res, qsum * worker[0]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> quality = {10, 20, 5};
    vector<int> wages = {70, 50, 30};
    int K = 2;
    cout << sol.mincostToHireWorkers(quality, wages, K) << endl;
    return 0;
}
