#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<long long> ans(n);

        // 1. create sorted vector with <value, i>
        priority_queue<pair<int, int>> minHeap;
        for (int i = 0; i < n; i++)
            minHeap.push({-nums1[i], i});

        // 2. iterate to find all smaller j's
        vector<int> js;
        int prevVal = 0;
        while (minHeap.size())
        {
            auto [val, i] = minHeap.top();
            minHeap.pop();

            if (val < prevVal)
                js.push_back(i);
            prevVal = val;

            // 3. max sum of atmost k nums2 values
            priority_queue<long long> pq; // minHeap for nums2[j]
            for (int j : js)
            {
                if ((int)pq.size() < k)
                    pq.push(nums2[j]);
                else if ((int)pq.size() == k && pq.top() < nums2[j])
                {
                    pq.pop();
                    pq.push(nums2[j]);
                }
            }

            long long maxSum = 0;
            while (pq.size())
            {
                maxSum += pq.top();
                pq.pop();
            }
            ans[i] = maxSum;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 2, 1, 5, 3};
    vector<int> nums2 = {10, 20, 30, 40, 50};
    int k = 2;
    vector<long long> ans = sol.findMaxSum(nums1, nums2, k);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}

// [4,2,1,5,3], nums2 = [10,20,30,40,50], k = 2
