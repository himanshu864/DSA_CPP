#include <iostream>
#include <vector>
using namespace std;

// My TLE
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(i);
        sort(ans.begin(), ans.end(), [&](int &a, int &b)
             {
                stack<int> x;
                stack<int> y;
                for(int i = a; i; i /= 10)
                    x.push(i % 10);
                for(int i = b; i; i /= 10)
                    y.push(i % 10);
                while(x.size() && y.size())
                {
                    if(x.top() == y.top())
                    {
                        x.pop();
                        y.pop();
                    }
                    else
                        return x.top() < y.top();
                }
                return x.empty(); });
        return ans;
    }
};

// Recursion God
class Solution2
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        helper(1, n, res);
        return res;
    }

    void helper(int target, int n, vector<int> &res)
    {
        if (target > n)
            return;
        res.push_back(target);
        helper(target * 10, n, res);
        if (target % 10 != 9)
            helper(target + 1, n, res);
    }
};

// Iterative God
class Solution3
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++)
        {
            res[i] = cur;
            if (cur * 10 <= n)
            {
                cur *= 10;
            }
            else
            {
                if (cur >= n)
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }
};

int main()
{
    Solution3 sol;
    int n = 13;
    vector<int> ans = sol.lexicalOrder(n);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/lexicographical-numbers/
