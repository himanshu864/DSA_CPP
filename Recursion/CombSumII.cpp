#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> &output, int x)
{
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    if (target < 0 || x == candidates.size())
        return;

    output.push_back(candidates[x]);
    helper(candidates, target - candidates[x], ans, output, x + 1);
    output.pop_back();

    x++;
    while (x < candidates.size() && candidates[x] == candidates[x - 1])
        x++;
    if (x < candidates.size())
        helper(candidates, target, ans, output, x);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    sort(candidates.begin(), candidates.end());
    helper(candidates, target, ans, output, 0);
    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 7;
    for (vector<int> i : combinationSum2(candidates, target))
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/combination-sum-ii/
