#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        // Binary Search to Partition into left and right halves
        int s = 0, e = m;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            // no. of elements in left half from nums1 and nums2
            int a = mid;
            int b = (m + n) / 2 - mid;

            // Boundary values of partition
            int Al = a > 0 ? nums1[a - 1] : INT_MIN;
            int Ar = a < m ? nums1[a] : INT_MAX;
            int Bl = b > 0 ? nums2[b - 1] : INT_MIN;
            int Br = b < n ? nums2[b] : INT_MAX;

            if (Al > Br)
                e = mid - 1;
            else if (Bl > Ar)
                s = mid + 1;
            else
            {
                int l = max(Al, Bl);
                int r = min(Ar, Br);
                return (m + n) % 2 == 0 ? (l + r) / 2.0 : r;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    // vector<int> nums1 = {1, 3, 4, 7, 10, 12};
    // vector<int> nums2 = {2, 3, 6, 15};
    cout << sol.findMedianSortedArrays(nums1, nums2) << '\n';
    return 0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/
