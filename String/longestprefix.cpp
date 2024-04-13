#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

string longestCommonPrefix(vector<string> &strs)
{
    // Here we sort strs and compare only first and last strings (best)
    string ans = "";
    sort(strs.begin(), strs.end());
    string first = strs[0], last = strs[strs.size() - 1];
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] == last[i])
            ans += first[i];
        else
            break;
    }

    // Here we straight up compare each pair of strings, and return the smallest one (Mine)
    // string ans = strs[0];
    // for (int i = 0; i < strs.size() - 1; i++)
    // {
    //     string common = "";
    //     string first = strs[i], second = strs[i + 1];
    //     for (int x = 0; x < first.size(); x++)
    //     {
    //         if (first[x] == second[x])
    //             common += first[x];
    //         else
    //             break;
    //     }
    //     if (common.size() < ans.size())
    //         ans = common;
    // }

    return ans;
}

// string longestCommonPrefixarray(string arr[], int N)
// {
//     sort(arr, arr + N);
//     string first = arr[0], last = arr[N - 1];
//     string ans = "";
//     for (int i = 0; i < first.size(); i++)
//     {
//         if (first[i] == last[i])
//             ans += first[i];
//         else
//             break;
//     }
//     return ans.empty() ? "-1" : ans;
// }

int main()
{
    int n;
    cin >> n;
    vector<string> nums(n);
    int size = nums.size();
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << longestCommonPrefix(nums);
    return 0;
}

// https://leetcode.com/problems/longest-common-prefix/
