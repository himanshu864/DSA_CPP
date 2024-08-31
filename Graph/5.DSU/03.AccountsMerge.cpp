#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionSet(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string>> ans;
        int n = accounts.size();
        DisjointSet dsu(n);

        // Map to track the first occurrence of each email
        unordered_map<string, int> emailMap; // {email, parent account index}

        // Step 1: Union accounts based on common emails
        for (int i = 0; i < accounts.size(); i++)
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j];
                // Union if email is already mapped
                if (emailMap.count(email))
                    dsu.unionSet(i, emailMap[email]);
                else
                    emailMap[email] = i;
            }

        // Step 2: Group emails by their root parent in Disjoint Set
        vector<set<string>> merged(n); // To store emails grouped by their root account
        for (auto &[email, accId] : emailMap)
            merged[dsu.find(accId)].insert(email);

        // Step 3: Create final merged accounts
        for (int i = 0; i < n; i++)
            if (merged[i].size())
            {
                vector<string> acc;
                acc.push_back(accounts[i][0]); // Add account name
                for (auto email : merged[i])
                    acc.push_back(email); // Add merged sorted emails
                ans.push_back(acc);
            }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r3@com", "r1@com"},
        {"Mary", "m1@com"},
    };
    vector<vector<string>> ans = sol.accountsMerge(accounts);
    for (auto account : ans)
    {
        for (string s : account)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/accounts-merge/
