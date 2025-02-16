#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(n * 2 - 1, 0);
        vector<bool> visited(n + 1, false);
        helper(0, ans, visited, n);
        return ans;
    }

private:
    bool helper(int index, vector<int> &ans, vector<bool> &visited, int n)
    {
        if (index == ans.size())
            return true;
        if (ans[index] != 0)
            return helper(index + 1, ans, visited, n);
        else
        {
            for (int i = n; i >= 1; i--)
            {
                if (visited[i])
                    continue;
                visited[i] = true;
                ans[index] = i;
                if (i == 1)
                {
                    if (helper(index + 1, ans, visited, n))
                        return true;
                }
                else if (index + i < ans.size() && ans[index + i] == 0)
                {
                    ans[i + index] = i;
                    if (helper(index + 1, ans, visited, n))
                        return true;
                    ans[index + i] = 0;
                }
                ans[index] = 0;
                visited[i] = false;
            }
        }
        return false;
    }
};

int main()
{
    int n = 4;
    cout << n << '\n';
    return 0;
}
