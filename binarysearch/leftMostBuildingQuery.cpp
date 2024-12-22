#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int qn = queries.size();
        vector<int> ans(qn);
        priority_queue<vector<int>> QSE; // queries_desc_sorted_by_right_pointer
        for (int i = 0; i < qn; i++)
        {
            int l = min(queries[i][0], queries[i][1]);
            int r = max(queries[i][0], queries[i][1]);

            if (l == r || heights[l] < heights[r])
                ans[i] = r;
            else
                QSE.push({r, l, i}); // {right, left, index}
        }

        vector<int> st; // monotonic_decreasing; push and pop back ; reversed
        for (int r = heights.size() - 1; r >= 0; r--)
        {
            while (QSE.size() && QSE.top()[0] == r)
            {
                int l = QSE.top()[1];
                int i = QSE.top()[2];
                QSE.pop();

                // binary search on monotonic to find closest (rightmost) building higher than [l]
                int t = -1;
                int s = 0, e = st.size() - 1;
                while (s <= e)
                {
                    int mid = s + (e - s) / 2;
                    int x = st[mid];
                    if (heights[x] > heights[l])
                    {
                        t = x;
                        s = mid + 1;
                    }
                    else
                        e = mid - 1;
                }
                ans[i] = t;
            }

            // maintain monotonic
            while (st.size() && heights[r] >= heights[st.back()])
                st.pop_back();
            st.push_back(r);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    vector<int> ans = sol.leftmostBuildingQueries(heights, queries);
    for (int i : ans)
        cout << i << " ";
    cout << '\n';
    return 0;
}

// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/
