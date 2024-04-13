#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    int largestRectangleArea(vector<int> &nums)
    {
        int ans = 0;
        stack<int> st;
        nums.push_back(0);
        for (int i : nums)
        {
            int width = 1;
            while (st.size() && st.top() > i)
            {
                ans = max(ans, st.top() * width++);
                st.pop();
            }
            while (width-- && i != 0)
                st.push(i);
        }
        nums.pop_back();
        return ans;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int ans = 0, cols = matrix[0].size();
        vector<int> bars(cols, 0);
        for (vector<char> r : matrix)
        {
            for (int i = 0; i < cols; i++)
            {
                if (r[i] == '1')
                    bars[i]++;
                else
                    bars[i] = 0;
            }
            ans = max(ans, largestRectangleArea(bars));
        }
        return ans;
    }
};

void printmat(vector<vector<char>> &matrix)
{
    for (vector<char> i : matrix)
    {
        for (char j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{
    Solution sol;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    printmat(matrix);
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}

// https://leetcode.com/problems/maximal-rectangle/
