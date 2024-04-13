#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// My Code:
// One Queens must be places on every row
// From there we keep a possible[][] to check any queen is attacking that place
// If not, push on column, update possible and move to next row
// Simple Bruteforce
// I don't like the fact that I have to use an extra temp[][] to revert possible
// First Try : 5:30PM 25-03-24
class Solution
{
    void Slayy(vector<vector<bool>> &possible, int row, int col, int n)
    {
        // plus
        for (int i = 0; i < n; i++)
        {
            possible[row][i] = false;
            possible[i][col] = false;
        }

        // cross
        int r = row, c = col;
        while (r < n && c < n)
            possible[r++][c++] = false;
        r = row, c = col;
        while (r >= 0 && c >= 0)
            possible[r--][c--] = false;
        r = row, c = col;
        while (r >= 0 && c < n)
            possible[r--][c++] = false;
        r = row, c = col;
        while (r < n && c >= 0)
            possible[r++][c--] = false;
    }
    void helper(vector<vector<string>> &ans, vector<string> &output,
                vector<vector<bool>> &possible, int n, int r)
    {
        if (r == n)
        {
            ans.push_back(output);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (possible[r][i])
            {
                string row(n, '.');
                row[i] = 'Q';
                output.push_back(row);
                vector<vector<bool>> original = possible;
                Slayy(possible, r, i, n); // Queen will slayy all 8 directions
                helper(ans, output, possible, n, r + 1);
                possible = original;
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> output;
        vector<vector<bool>> possible(n, vector<bool>(n, true));
        helper(ans, output, possible, n, 0);
        return ans;
    }
};

// Neetcode: Use hashset col, neg, pos to check instead on possible
// all columns must be different, unordered_set as unique as easy check
// neg is negative diagonal: top left to bottom right
// : as both row and col increase linearly, there difference must be same and unique for every diagonal
// Similarly for positive diagonal: top right to bottom right: row increase, and col decrease, hence sum same

class Solution2
{
    void helper(vector<vector<string>> &ans, vector<string> &output,
                unordered_set<int> &col, unordered_set<int> &neg,
                unordered_set<int> &pos, int n, int r)
    {
        if (r == n)
        {
            ans.push_back(output);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!col.count(i) && !neg.count(i - r) && !pos.count(i + r))
            {
                string row(n, '.');
                row[i] = 'Q';
                output.push_back(row);
                col.insert(i);
                neg.insert(i - r);
                pos.insert(i + r);
                helper(ans, output, col, neg, pos, n, r + 1);
                col.erase(i);
                neg.erase(i - r);
                pos.erase(i + r);
                output.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> output;
        unordered_set<int> col, neg, pos;
        helper(ans, output, col, neg, pos, n, 0);
        return ans;
    }
};

int main()
{
    Solution2 sol;
    int n = 4;
    vector<vector<string>> ans = sol.solveNQueens(n);
    for (vector<string> x : ans)
    {
        for (string s : x)
            cout << s << endl;
        cout << endl;
    }
    return 0;
}

// https://leetcode.com/problems/find-all-duplicates-in-an-array/
