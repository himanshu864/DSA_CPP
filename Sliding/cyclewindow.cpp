#include <iostream>
#include <vector>
using namespace std;

// if k > 0; sum of next k elements, and previous or k < 0
// My decent O(n^2) solution
vector<int> decrypt2(vector<int> &code, int k)
{
    int n = code.size();
    vector<int> ans(n, 0);
    if (k == 0)
        return ans;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        if (k > 0)
            for (int j = 1; j <= k; j++)
                sum += code[(i + j) % n];
        else
            for (int j = 1; j <= (-k); j++)
                sum += code[(((i - j) % n) + n) % n];
        ans[i] = sum;
    }
    return ans;
}

// my kinda complicated linear sliding window approach
vector<int> decrypt(vector<int> &code, int k)
{
    int n = code.size();
    vector<int> ans(n, 0);
    if (k > 0)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += code[i];
        for (int i = 0; i < n; i++)
        {
            sum -= code[i];
            sum += code[(i + k) % n];
            ans[i] = sum;
        }
    }
    else if (k < 0)
    {
        k *= (-1);
        int sum = 0;
        for (int i = 2; i <= (k + 1); i++)
            sum += code[n - i];
        for (int i = 0; i < n; i++)
        {
            sum -= code[((i - k - 1) % n + n) % n];
            sum += code[((i - 1) % n + n) % n];
            ans[i] = sum;
        }
    }
    return ans;
}

int main()
{
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    // vector<int> code = {2, 4, 9, 3};
    // int k = -2;
    for (int i : decrypt(code, k))
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/defuse-the-bomb/
