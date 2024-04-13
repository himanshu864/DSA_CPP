#include <iostream>
#include <vector>
using namespace std;

int assist(vector<int> &nums1, vector<int> &nums2, int &i, int &j)
{
    if (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] <= nums2[j])
            return nums1[i++];
        else
            return nums2[j++];
    }
    else if (i < nums1.size())
        return nums1[i++];
    return nums2[j++];
}

double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2)
{
    double ans = 0;
    int size = (nums1.size() + nums2.size() + 1) / 2;
    int i = 0, j = 0;
    while (size--)
        ans = assist(nums1, nums2, i, j);
    if ((nums1.size() + nums2.size()) % 2)
        return ans;
    return (ans + assist(nums1, nums2, i, j)) / 2;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if (m > n) // to apply bs on shorter array
        return findMedianSortedArrays(nums2, nums1);

    // apply bs on number of element on left of median from first array
    int s = 0, e = m;
    while (s <= e)
    {
        int first = s + (e - s) / 2;
        int second = ((m + n) / 2) - first; // directly related for odd test cases

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (first > 0)
            l1 = nums1[first - 1];
        if (first != m)
            r1 = nums1[first];
        if (second > 0)
            l2 = nums2[second - 1];
        if (second != n)
            r2 = nums2[second];

        if (l1 > r2) // first array is bigger on left, decrease first
            e = first - 1;
        else if (l2 > r1) // second array is bigger, hence increase first
            s = first + 1;
        else // perfectly symmetrical median division
        {
            if ((m + n) % 2) // for odd
                return min(r1, r2);
            return (max(l1, l2) + min(r1, r2)) / 2.0; // max of left side and min of right side are medians
        }
    }
    return -1; // dummy return
}

int main()
{
    vector<int> nums1 = {1, 3, 4, 7, 10, 12};
    vector<int> nums2 = {2, 3, 6, 15};
    // vector<int> nums1 = {1, 2};
    // vector<int> nums2 = {3, 4};
    // vector<int> nums1 = {1, 3, 5};
    // vector<int> nums2 = {2, 4};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
    return 0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/

// watch video to understand intuition
// every little indexing is important to avoid major edge cases

// apply bs on smaller array to avoid out of bounds edge cases:
// - where no. of elements from first array exceed total elements on left
// - and elements req from second array exceed its size

// initialize l1, l2 = INT_MIN and r1, r2 = INT_MAX to avoid repetitive edge cases
// of checking how of them doesn't exist (first/second > 0 && < m/n)
// and comparing max(l1, l2) and min(r1, r2) become 100x easier

// empty and odd cases are also included
