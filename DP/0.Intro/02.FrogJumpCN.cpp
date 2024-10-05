#include <iostream>
#include <vector>
using namespace std;

/*
If have to check all possible paths via - best way or total ways
RECURSION! or rather Dynamic Programming!
Then use following abstract steps to find out recursive relation

1. Try to represent problem in terms of indices
2. Do stuff on those indices according to problem
3. if asked total ways = sum indices or min/max indices
*/

int frogJump(int n, vector<int> &heights)
{
    if (n == 0 || n == 1)
        return 0;
    int one = frogJump(n - 1, heights) + abs(heights[n - 2] - heights[n - 1]);
    int two = frogJump(n - 2, heights) + abs(heights[n - 3] - heights[n - 1]);
    return min(one, two);
}

int main()
{
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights) << endl;
    return 0;
}
