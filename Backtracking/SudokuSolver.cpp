#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool isSafe(vector<vector<char>> &board, int r, int c, char x)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == x)
                return false;
            if (board[i][c] == x)
                return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == x) // concise big brain
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (char x = '1'; x <= '9'; x++)
                {
                    if (isSafe(board, i, j, x))
                    {
                        board[i][j] = x;

                        if (solve(board) == true) // genius recursion
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) { solve(board); }
};

int main()
{
    Solution sol;
    vector<vector<char>> board =
        {{'5', '3', '.', '.', '7', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    sol.solveSudoku(board);

    for (vector<char> i : board)
    {
        for (char j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
