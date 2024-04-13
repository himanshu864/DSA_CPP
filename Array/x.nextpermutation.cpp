#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size();
    int k, l;
    for (k = n - 2; k >= 0; k--)
        if (A[k] < A[k + 1])
            break;

    if (k < 0)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    else
        for (l = n - 1; l > k; l--)
            if (A[l] > A[k])
                break;

    swap(A[l], A[k]);
    reverse(A.begin() + k + 1, A.end());
    return A;
}

int main()
{
    vector<int> A = {6, 1, 4, 5, 3, 2};
    for (int i : nextGreaterPermutation(A))
        cout << i;
    return 0;
}

// 1. Longer Prefix Match: Find index from the end where the array dips/breaks
// a[i] < a[i + 1]
// 2. Now to the right of index, we'll have a decreasing array, hence reverse == sort
// 2.5. Hence, If no breaking point, the next permunation will be sorted/reversed array
// We want a number just greater than at a[i] to find the ans
// Hence, search from end to k, until find > a[i] and swap them
// 3. Sort/reverse the right side to make the array as small as possible
