#include <iostream>
#include <vector>
using namespace std;

// remember to pop ans if passed by reference

void subseqk(int *arr, int n, int k, vector<int> ans, int sum)
{
    if (n < 0 || sum > k)
        return;
    if (sum == k)
    {
        for (int i : ans)
            cout << i << " ";
        cout << endl;
        return;
    }
    subseqk(arr + 1, n - 1, k, ans, sum);
    ans.push_back(arr[0]);
    sum += arr[0];
    subseqk(arr + 1, n - 1, k, ans, sum);
}

int main()
{
    int arr[3] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    vector<int> ans;
    subseqk(arr, n, k, ans, 0);
    return 0;
}
