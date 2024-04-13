#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int x = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[x--] = nums1[i--];
        else
            nums1[x--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int n = nums2.size();
    int m = nums1.size() - n;
    merge(nums1, m, nums2, n);
    for (int i : nums1)
        cout << i << " ";
    return 0;
}

// https://leetcode.com/problems/merge-sorted-array/
