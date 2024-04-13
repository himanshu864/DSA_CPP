#include <iostream>
#include <vector>
using namespace std;

int maxsumsubarrlenk(vector<int> a, int k)
{
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (i >= k)
            sum -= a[i - k];
        if (i >= k - 1)
            ans = max(ans, sum);
    }
    return ans;
}

int maxsumsubarrlenk2(vector<int> a, int k)
{
    if (a.size() < k)
        return -1;

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i];

    int ans = sum;
    for (int i = k; i < a.size(); i++)
    {
        sum += a[i];
        sum -= a[i - k];
        if (sum > ans)
            ans = sum;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 2, 6, 7, 2, 4, 1, 3, 10};
    int sublen = 4;
    int result = maxsumsubarrlenk2(arr, sublen);
    cout << "Maximum sum of subarray of " << sublen << " length: " << result << endl;
    return 0;
}
