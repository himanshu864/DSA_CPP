#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &A)
    {
        int res = 0;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[0].size(); res += A[i][j++])
                if (A[i][j] && i && j)
                    A[i][j] += min({A[i - 1][j - 1], A[i - 1][j], A[i][j - 1]});
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1},
    };
    cout << sol.countSquares(matrix) << endl;
    return 0;
}

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
