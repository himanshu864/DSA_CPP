#include <iostream>
#include <vector>
using namespace std;

vector<int> primefact(int N)
{
    vector<int> ans;
    vector<bool> checkpp(N, true);
    int i = 2;
    while (N > 1)
    {
        if (N % i == 0)
        {
            if (checkpp[i])
            {
                ans.push_back(i);
                checkpp[i] = false;
            }
            N /= i;
        }
        else
            i++;
    }
    return ans;
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;
    vector<int> testing = primefact(N);
    for (int i : testing)
        cout << i << endl;
    return 0;
}
