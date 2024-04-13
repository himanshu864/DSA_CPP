#include <bits/stdc++.h>
using namespace std;

// my sliding window using queue
vector<int> firstNeg(vector<int> arr, int n, int k)
{
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);

        if (i >= k && arr[i - k] == q.front())
            q.pop();

        if (i + 1 >= k)
        {
            if (q.empty())
                ans.push_back(0);
            else
                ans.push_back(q.front());
        }
    }
    return ans;
}

// Optimized one pointer one window made by yours truly
vector<int> firstNegative(vector<int> arr, int n, int k)
{
    vector<int> ans;
    int mini = 0;      // stay at first minimum element as long as in window
    int i = 0;         // to keep track of first element in a window, moves with the window
    while (i <= n - k) // first element of last window
    {
        if (arr[mini] < 0 && mini >= i && mini < i + k) // if mini -ve and lies inside the window
        {
            ans.push_back(arr[mini]);
            i++; // push and move to next window
        }
        else if (mini >= i + k) // if mini exceeds current window
        {
            ans.push_back(0); // means no negative in that window
            i++;              // hence, next
        }
        else // here, either mini out pushed out, or is still in the window, but arr[min] not neg
            mini++;
    }
    return ans;
}

// Aditya verma solution:
vector<int> FirstNegativeIntegers(vector<int> A, int N, int K)
{
    vector<int> ans;
    queue<int> l;
    int i = 0, j = 0;
    while (j < N)
    {
        if (A[j] < 0)
            l.push(A[j]);

        if (j - i + 1 < K)
            j++;

        else if (j - i + 1 == K)
        {
            if (l.size() == 0)
                ans.push_back(0);
            else
            {
                ans.push_back(l.front());
                if (A[i] == l.front())
                    l.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> arr = {5, -3, 2, 3, -4};
    int k = 2;
    vector<int> test = firstNegative(arr, n, k);
    for (int b : test)
        cout << b << endl;
    return 0;
}

// not sure what that is, but looks useful
// https://leetcode.com/discuss/interview-question/3100856/Fixed-Size-Sliding-Window-(Important-Questions-with-Solutions)

// https://www.codingninjas.com/studio/problems/first-negative-in-every-window_759333
