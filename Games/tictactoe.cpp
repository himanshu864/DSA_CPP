#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> grid = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
bool playerOneTurn = true;
bool gameOver = false;

void printGrid()
{
    cout << "  0   1   2 " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " +---+---+---+" << endl;
        cout << i;
        for (int j = 0; j < 3; j++)
            cout << "| " << (grid[i][j] == -1 ? ' ' : (grid[i][j] == 1 ? 'X' : 'O')) << " ";
        cout << "|" << endl;
    }
    cout << " +---+---+---+" << endl;
    cout << endl;
}

void inputGrid()
{
    int row, col;
    bool validInput = false;

    while (!validInput)
    {
        printGrid();
        cout << "> It's your turn, Player " << (playerOneTurn ? 1 : 2) << endl;

        cout << "Enter row (0-2): ";
        while (!(cin >> row) || row < 0 || row > 2)
        {
            cout << "> Incorrect Input, Try again! Enter row (0-2): ";
            cin.clear();                                         // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the incorrect input
        }

        cout << "Enter col (0-2): ";
        while (!(cin >> col) || col < 0 || col > 2)
        {
            cout << "> Incorrect Input, Try again! Enter col (0-2): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (grid[row][col] != -1)
        {
            cout << "> Already Taken, Try again!" << endl;
        }
        else
        {
            grid[row][col] = playerOneTurn ? 1 : 0;
            playerOneTurn = !playerOneTurn;
            validInput = true;
        }
    }
}

// Flag every line for each player
bool linecheck(int x)
{
    bool diagLR = true;
    bool diagRL = true;

    for (int i = 0; i < 3; i++)
    {
        bool hori = true;
        bool verti = true;

        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != x)
                hori = false;

            if (grid[j][i] != x)
                verti = false;
        }
        if (hori || verti)
            return true;

        if (grid[i][i] != x)
            diagLR = false;

        if (grid[i][2 - i] != x)
            diagRL = false;
    }
    return diagLR || diagRL;
}

int scoreMate()
{
    if (linecheck(1))
        return 1; // Player 1 wins
    if (linecheck(0))
        return 0; // Player 0 wins

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == -1)
                return -1; // Game ongoing

    return 2; // Draw
}

void areYouWinningSon()
{
    int result = scoreMate();

    if (result != -1)
    {
        if (result == 1)
            cout << "You win, Player One!" << endl;
        if (result == 0)
            cout << "You win, Player Two!" << endl;
        if (result == 2)
            cout << "It's a Draw!" << endl;
        gameOver = true;
    }
    cout << endl;
}

int main()
{
    while (!gameOver)
    {
        inputGrid();
        areYouWinningSon();
    }
    return 0;
}
