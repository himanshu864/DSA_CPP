#include <bits/stdc++.h>
using namespace std;

vector<int> maximumsumSubarray(vector<int> &arr)
{
    int maxi = arr[0]; // don't set to zero, either INT_MIN or this
    int sum = 0;
    int start = 0, end = 0;
    int temp_s = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > maxi) // this condition should be before sum < 0 to handle negative max
        {
            start = temp_s;
            end = i;
            maxi = sum;
        }
        if (sum < 0)
        {
            if (i != arr.size() - 1)
                temp_s = i + 1;
            sum = 0;
        }
    }
    cout << "Start: " << start << " and End: " << end << endl;
    cout << "Max: " << maxi << endl;
    vector<int> ans;
    for (int i = start; i <= end; i++)
        ans.push_back(arr[i]);
    return ans;
}

int main()
{
    // vector<int> arr = {1, 2, 5, -8, 2, -3, 1, 1, 5};
    // vector<int> arr = {1, 2, 5, -8, 2, -3, 4, 5};
    vector<int> arr = {-3, -4, -2, -1, -3};
    vector<int> max_subarray = maximumsumSubarray(arr);
    for (int i : max_subarray)
        cout << i << " ";
    return 0;
}
