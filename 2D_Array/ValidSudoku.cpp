#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char x = board[i][j];
                if (x == '.')
                    continue;
                for (int k = 0; k < 9; k++)
                {
                    if (k != j && board[i][k] == x)
                        return false;
                    if (k != i && board[k][j] == x)
                        return false;

                    int row = 3 * (i / 3) + k / 3;
                    int col = 3 * (j / 3) + k % 3;
                    if (row != i && col != j)
                        if (board[row][col] == x)
                            return false;
                }
            }
        }
        return true;
    }
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

    cout << sol.isValidSudoku(board) << endl;

    return 0;
}
