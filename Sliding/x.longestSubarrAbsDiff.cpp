#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

/*
int longestSubarray(vector<int> &A, int limit)
{
    deque<int> maxd, mind;
    int i = 0, j;
    for (j = 0; j < A.size(); ++j)
    {
        while (!maxd.empty() && A[j] > maxd.back())
            maxd.pop_back();
        while (!mind.empty() && A[j] < mind.back())
            mind.pop_back();
        maxd.push_back(A[j]);
        mind.push_back(A[j]);
        if (maxd.front() - mind.front() > limit)
        {
            if (maxd.front() == A[i])
                maxd.pop_front();
            if (mind.front() == A[i])
                mind.pop_front();
            ++i;
        }
    }
    return j - i;
}
*/

class Solution
{
public:
    int longestSubarray(vector<int> &A, int limit)
    {
        int i = 0, j;
        multiset<int> m;
        for (j = 0; j < A.size(); ++j)
        {
            m.insert(A[j]);
            while (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(A[i++]));
        }
        return j - i;
    }
};

int main()
{
    multiset<int> s;
    s.insert(4);
    s.insert(2);
    s.insert(1);
    s.insert(1);
    for (auto i : s)
        cout << i << endl;

    return 0;
}

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
