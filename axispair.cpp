#include <bits/stdc++.h>
using namespace std;

int numberOfPairs(vector<vector<int>> &points)
{
    int ans = 0;
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points.size(); j++)
        {
            if (i != j)
            {
                if (points[i][0] < points[j][0] && points[i][1] == points[j][1])
                {
                    bool flag = true;
                    for (int k = 0; k < points.size(); k++)
                    {
                        if (k != i && k != j)
                        {
                            if (points[i][0] < points[k][0] && points[k][0] < points[j][0])
                            {
                                flag = false;
                            }
                        }
                    }
                    if (flag)
                    {
                        cout << points[i][0] << " " << points[i][1] << endl;
                        cout << points[j][0] << " " << points[j][1] << endl;
                        ans++;
                    }
                }
                else if (points[i][0] == points[j][0] && points[i][1] > points[j][1])
                {
                    bool flag = true;
                    for (int k = 0; k < points.size(); k++)
                    {
                        if (k != i && k != j)
                        {
                            if (points[i][1] > points[k][1] && points[k][1] > points[j][1])
                            {
                                flag = false;
                            }
                        }
                    }
                    if (flag)
                    {
                        cout << points[i][0] << " " << points[i][1] << endl;
                        cout << points[j][0] << " " << points[j][1] << endl;
                        ans++;
                    }
                }
                else if (points[i][0] < points[j][0] && points[i][1] > points[j][1])
                {
                    bool flag = true;
                    for (int k = 0; k < points.size(); k++)
                    {
                        if (k != i && k != j)
                        {
                            if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1])
                            {
                                flag = false;
                            }
                        }
                    }
                    if (flag)
                    {
                        cout << points[i][0] << " " << points[i][1] << endl;
                        cout << points[j][0] << " " << points[j][1] << endl;
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{3, 1}, {1, 3}, {1, 1}};
    // vector<vector<int>> arr = {{6, 2}, {4, 4}, {2, 6}};
    // [[3,1],[1,3],[1,1]]
    cout << numberOfPairs(arr);
    return 0;
}
