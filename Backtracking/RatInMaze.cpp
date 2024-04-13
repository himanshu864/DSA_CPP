#include <iostream>
#include <vector>
using namespace std;

// all datatypes passed by reference, hence undo changes for backtracking
void helper(vector<vector<int>> m, int n, vector<string> &ans, string &output, vector<bool> visited, int row, int col)
{
    // order is important to avoid segmentable error
    if (row < 0 || row >= n || col < 0 || col >= n || m[row][col] == 0 || visited[row * n + col])
        return;

    if (row == (n - 1) && col == (n - 1))
    {
        ans.push_back(output);
        return;
    }

    visited[row * n + col] = true;
    output += "U";
    helper(m, n, ans, output, visited, row - 1, col);
    output.pop_back();
    output += "R";
    helper(m, n, ans, output, visited, row, col + 1);
    output.pop_back();
    output += "D";
    helper(m, n, ans, output, visited, row + 1, col);
    output.pop_back();
    output += "L";
    helper(m, n, ans, output, visited, row, col - 1);
    output.pop_back();
    // visited[row * n + col] = false; // backtracking
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    string output = "";
    vector<bool> visited(n * n, false);
    helper(m, n, ans, output, visited, 0, 0);
    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    for (string s : findPath(m, n))
        cout << s << endl;
    return 0;
}

// start from 0, 0 and send recursions in all directions at every coordinate
// and return the paths that make it to the destination
// keep track of all the visited coordinates
// if coordinate is out of bounds, blocked aur visited already. simply return

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
