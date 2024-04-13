#include <bits/stdc++.h>
using namespace std;

// inplace: just learn how to store and access two values from one index
// using simple maths concept of divident = divisor * qouteint + remainder
// hence, divident % divisor = remainder
// and divident / divisor = qouteint
// use MAX as any value greator than maximum value of array to use / and % properly
// then use big brain to alter above concept to array (basically imagine max to be 1000 and try to solve stepy by step)
// if i is even, maxIndex--, else minIndex++: the usual
// finally divide the entire array by MAX to get final answer
void rearrangeAlt(int *arr, int n)
{
    int minIndex = 0;
    int maxIndex = n - 1;
    int MAX = arr[n - 1] + 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            arr[i] += (arr[maxIndex--] % MAX) * MAX;
        else
            arr[i] += (arr[minIndex++] % MAX) * MAX;
    }
    for (int i = 0; i < n; i++)
        arr[i] /= MAX;
}

// using extra space
vector<int> rearrangeAltx(int *arr, int n)
{
    vector<int> temp;
    int minIndex = 0;
    int maxIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            temp.push_back(arr[maxIndex--]);
        else
            temp.push_back(arr[minIndex++]);
    }
    return temp;
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i : rearrangeAltx(arr, 6))
        cout << i << " ";
    cout << endl;

    rearrangeAlt(arr, 6);
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
