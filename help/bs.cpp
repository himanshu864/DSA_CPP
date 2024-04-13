#include <iostream>
#include <vector>
using namespace std;

void choose(int check, int &a0, int &a1, int &a2)
{
    if (check == 0)
        a0++;
    else if (check == 1)
        a1++;
    else
        a2++;
}

int minimumOperationsToWriteY(vector<vector<int>> &grid)
{
    int n = grid.size();
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            choose(grid[i][j], c0, c1, c2);

    int y0 = 0, y1 = 0, y2 = 0;
    for (int i = 0; i < (n / 2); i++)
    {
        choose(grid[i][i], y0, y1, y2);
        choose(grid[i][n - i - 1], y0, y1, y2);
        choose(grid[(n / 2) + i][n / 2], y0, y1, y2);
    }
    choose(grid[n - 1][n / 2], y0, y1, y2);

    c0 -= y0;
    c1 -= y1;
    c2 -= y2;

    bool b0 = false, b1 = false, b2 = false;
    int maxrest = 0;
    if (c0 > c1 && c0 > c2)
    {
        b0 = true;
        maxrest = c0;
    }
    else if (c1 > c0 && c1 > c2)
    {
        b1 = true;
        maxrest = c1;
    }
    else if (c2 > c0 && c2 > c1)
    {
        b2 = true;
        maxrest = c2;
    }
    else if (c0 == c1 && c1 == c2)
    {
        if (y0 >= y1 && y0 >= y2)
        {
            maxrest = c2;
            bool b2 = true;
        }
        else if (y1 >= y0 && y1 >= y2)
        {

            maxrest = c0;
            bool b0 = true;
        }
        else
        {

            maxrest = c1;
            bool b1 = true;
            if (b0)
                cout << 0 << endl;
            else if (b1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        if (b0)
            cout << 0 << endl;
        else if (b1)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    else if ((c0 == c1) && c0 > c2)
    {
        if (y0 >= y1)
        {
            maxrest = c1;
            b1 = true;
        }
        else
        {
            maxrest = c0;
            b0 = true;
        }
    }
    else if ((c1 == c2) && c1 > c0)
    {
        if (y1 >= y2)
        {
            maxrest = c2;
            bool b2 = true;
        }
        else
        {
            maxrest = c1;
            bool b1 = true;
        }
    }
    else
    {
        if (y0 >= y2)
        {
            maxrest = c2;
            bool b2 = true;
        }
        else
        {
            maxrest = c0;
            bool b0 = true;
        }
    }

    int maxy = 0;
    if (b0)
        maxy = max(y1, y2);
    else if (b1)
        maxy = max(y0, y2);
    else
        maxy = max(y0, y1);

    cout << c0 << " " << c1 << " " << c2 << endl;
    cout << y0 << " " << y1 << " " << y2 << endl;
    cout << maxrest << " " << maxy << endl;

    int ans = (n * n) - maxrest - maxy;
    return ans;
}

int main()
{
    // vector<vector<int>> grid = {{1, 2, 2}, {1, 1, 0}, {0, 1, 0}};
    vector<vector<int>> grid = {{2, 2, 0, 0, 2}, {2, 1, 1, 1, 2}, {1, 0, 0, 2, 1}, {2, 0, 2, 0, 1}, {1, 0, 2, 1, 2}};
    cout << minimumOperationsToWriteY(grid) << endl;
    for (vector<int> i : grid)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

// [[2,2,0,0,2],[2,1,1,1,2],[1,0,0,2,1],[2,0,2,0,1],[1,0,2,1,2]]