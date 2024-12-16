#include <bits/stdc++.h>
using namespace std;

// Genius Solution with 2 Bellman Fords
class Solution
{
    unordered_map<string, double> amount; // [curr] -> max Amount
    void bellman(vector<vector<string>> &pairs, vector<double> &rates)
    {
        int n = pairs.size();
        for (int relax = 0; relax < n; relax++)
            for (int i = 0; i < n; i++)
            {
                amount[pairs[i][1]] = max(amount[pairs[i][1]], amount[pairs[i][0]] * rates[i]);
                amount[pairs[i][0]] = max(amount[pairs[i][0]], amount[pairs[i][1]] / rates[i]);
            }
    }

public:
    double maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1,
                     vector<vector<string>> &pairs2, vector<double> &rates2)
    {
        amount[initialCurrency] = 1;
        bellman(pairs1, rates1);
        bellman(pairs2, rates2);
        return amount[initialCurrency];
    }
};

// My solution with 2 BFS
class Solution2
{
    unordered_map<string, double> visited; // curr -> max Amount

    unordered_map<string, vector<pair<string, double>>> adjList(vector<vector<string>> &pairs, vector<double> &rates)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < rates.size(); i++)
        {
            adj[pairs[i][0]].push_back({pairs[i][1], rates[i]});
            adj[pairs[i][1]].push_back({pairs[i][0], 1 / rates[i]});
        }
        return adj;
    }

    void bfs(string initialCurrency, unordered_map<string, vector<pair<string, double>>> &adj)
    {
        queue<pair<string, double>> q;
        q.push({initialCurrency, visited[initialCurrency]});

        while (q.size())
        {
            string curr = q.front().first;
            double money = q.front().second;
            q.pop();

            for (pair<string, double> x : adj[curr])
            {
                string newCurr = x.first;
                double rate = x.second;
                double newMoney = money * rate;

                if (visited[newCurr] < newMoney)
                {
                    visited[newCurr] = newMoney;
                    q.push({newCurr, newMoney});
                }
            }
        }
    }

public:
    double maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1,
                     vector<vector<string>> &pairs2, vector<double> &rates2)
    {
        // contruct graphs
        auto adj1 = adjList(pairs1, rates1);
        auto adj2 = adjList(pairs2, rates2);

        // find max Amounts on day1
        visited[initialCurrency] = 1;
        bfs(initialCurrency, adj1);

        // store currencies visited on day1
        vector<string> visitedCurr;
        for (auto &[curr, amount] : visited)
            visitedCurr.push_back(curr);

        // find max max Amounts on day2, from each visitedCurr
        for (auto curr : visitedCurr)
            bfs(curr, adj2);

        return visited[initialCurrency];
    }
};

int main()
{
    Solution sol;
    string initialCurrency = "EUR";
    vector<vector<string>> pairs1 = {{"EUR", "USD"}, {"USD", "JPY"}};
    vector<double> rates1 = {2.0, 3.0};
    vector<vector<string>> pairs2 = {{"JPY", "USD"}, {"USD", "CHF"}, {"CHF", "EUR"}};
    vector<double> rates2 = {4.0, 5.0, 6.0};
    cout << sol.maxAmount(initialCurrency, pairs1, rates1, pairs2, rates2) << '\n';
    return 0;
}

// https://leetcode.com/problems/maximize-amount-after-two-days-of-conversions/
