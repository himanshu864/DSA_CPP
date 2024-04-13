#include <iostream>
#include <vector>
using namespace std;

// big brain O(N) solution
// basically if all elements are bigger than k, k will be the ans
// as some elements are smaller(hence not missing), k increases
int findKthPositive(vector<int> &arr, int k)
{
    for (int i : arr)
    {
        if (i <= k)
            k++;
        else
            break;
    }
    return k;
}

int findKthPositive(vector<int> &arr, int k)
{
    // we need to find indexes of arr, in b/w where kth missing no. lies
    // eg: in arr 1, 3, 7;
    // ideally there should be 1, 2, 3 numbers, hence
    // 0th index is missing 0 number
    // 1st is missing 1 (2)
    // 2nd is missing 4 (2, 4, 5, 6)
    // hence no. of missing numbers = arr[i] - (i + 1);

    // So, if we were to find 2nd missing no.
    // it would lie b/w 3 and 7,
    // as they are missing 1 and 4 no.s
    // our ans will be 3 + (no. of more missing no. req)
    // ans = 3 + (2 - 1), because we need 2nd missing,
    // and 3 is already missing one
    // hence, 2nd missing no. is 4

    // that's why we need to apply bs on missing no. of array
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int missing = arr[mid] - mid - 1;
        if (missing < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start + k;
    // after bs, end become lower bound for missing number
    // now, missing number will lie b/w end and start index
    // ans = arr[end] + no. of more missing req.
    // more = k - missing;
    // more = k - (arr[end] - end - 1);
    // ans = arr[end] + k - arr[end] + end + 1;
    // ans = k + end + 1
    // and, start = end + 1; for them to break while loop
    // therefore, ans = k + start; simply satisfied.
    // watch striver video or lee if you still don't get it
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << findKthPositive(arr, k);
    return 0;
}

// https://leetcode.com/problems/kth-missing-positive-number/
