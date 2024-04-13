#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> output, int x)
{
    if (x == candidates.size() || target < 0)
        return;
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    helper(candidates, target, ans, output, x + 1);
    output.push_back(candidates[x]);
    helper(candidates, target - candidates[x], ans, output, x);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    helper(candidates, target, ans, output, 0);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 4};
    int target = 7;
    for (vector<int> i : combinationSum(candidates, target))
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
