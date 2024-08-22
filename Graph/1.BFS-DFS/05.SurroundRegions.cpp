#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = 'E'; // Mark as 'E' to indicate it's an edge-connected 'O'
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        // Step 1: Mark all 'O's connected to the edge
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Step 2: Flip all 'O' to 'X', except those marked as 'E'
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O'; // Revert the mark back to 'O'
            }
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    sol.solve(board);

    // Print the output
    for (const auto &row : board)
    {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}

// https://leetcode.com/problems/surrounded-regions/
