#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
    // memoize books with their position on shelf
    unordered_map<int, unordered_map<int, int>> memo;

    int helper(vector<vector<int>> &books, int shelfWidth, int i, int wsum, int hmax, int hsum)
    {
        if (i == books.size())
            return hsum + hmax;

        if (memo.count(i) && memo[i].count(wsum))
            return memo[i][wsum];

        int res;
        if (wsum == 0)
            res = helper(books, shelfWidth, i + 1, books[i][0], books[i][1], hsum);
        else if (wsum + books[i][0] > shelfWidth)
            res = hsum + hmax + helper(books, shelfWidth, i, 0, 0, 0);
        else
            res = min(
                helper(books, shelfWidth, i + 1, wsum + books[i][0], max(hmax, books[i][1]), hsum),
                hsum + hmax + helper(books, shelfWidth, i, 0, 0, 0));

        memo[i][wsum] = res;
        return res;
    }

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        memo.clear();
        return helper(books, shelfWidth, 0, 0, 0, 0);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    cout << sol.minHeightShelves(books, shelfWidth) << endl;
    return 0;
}

// https://leetcode.com/problems/filling-bookcase-shelves
