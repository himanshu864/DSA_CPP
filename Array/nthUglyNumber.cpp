#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class solution
{

public:
    // array - o(n)
    // we go this merge-sort 3 sorted array solution
    // just take care of when same all three produce same number
    // in that case, add one the factor to answer and increase all same indices
    int nthuglynumber(int n)
    {
        int i2 = 0, i3 = 0, i5 = 0;
        vector<long long> p(n);
        p[0] = 1;
        for (int i = 1; i < n; i++)
        {
            int p2 = p[i2] * 2;
            int p3 = p[i3] * 3;
            int p5 = p[i5] * 5;

            int mini = min(p2, min(p3, p5));
            p[i] = mini;

            if (mini == p2)
                i2++;
            if (mini == p3)
                i3++;
            if (mini == p5)
                i5++;
        }
        return p[n - 1];
    }
    // heap
    // to produce all factors. multiple 1 with {2,3,5}
    // then add all factors in a minheap to calc smallest
    // and calc that will {2,3,5}. similar keep adding and popping until n pops.
    int nthuglynumber2(int n)
    {
        unordered_set<long long> isugly;
        priority_queue<long long, vector<long long>, greater<long long>>
            minheap;
        minheap.push(1);
        vector<int> uglies = {2, 3, 5};
        long long x;
        for (int i = 1; i <= n; i++)
        {
            x = minheap.top();
            minheap.pop();

            for (long long u : uglies)
                if (!isugly.count(u * x))
                {
                    minheap.push(u * x);
                    isugly.insert(u * x);
                }
        }
        return x;
    }
};

int main()
{
    solution sol;
    int n = 11;
    cout << sol.nthuglynumber(n);
    return 0;
}

// https://leetcode.com/problems/ugly-number-ii/
