#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 1;
        while (arr[i] == arr[i + 1] && i < arr.size() - 1)
        {
            count++;
            i++;
        }
        ans.push_back(count);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (ans.size() - 1); i++)
        if (ans[i] == ans[i + 1])
            return false;
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 2};
    if (uniqueOccurrences(arr))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

// https://leetcode.com/problems/unique-number-of-occurrences/