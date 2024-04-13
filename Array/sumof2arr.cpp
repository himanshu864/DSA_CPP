#include <iostream>
using namespace std;

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
    int a = size1 - 1, b = size2 - 1;
    int carry = 0, i = max(size1, size2);

    while (a >= 0 || b >= 0)
    {
        int x = (a >= 0) ? input1[a--] : 0;
        int y = (b >= 0) ? input2[b--] : 0;

        int ans = x + y + carry;
        output[i--] = ans % 10;
        carry = ans / 10;
    }

    output[0] = carry;
}

/*
vector<int> addToArrayForm(vector<int> &num, int k)
{
    reverse(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++)
    {
        num[i] += k;
        k = num[i] / 10;
        num[i] = num[i] % 10;
    }
    while (k)
    {
        num.push_back(k % 10);
        k /= 10;
    }
    reverse(num.begin(), num.end());
    return num;
}
*/

int main()
{
    int size1;
    cin >> size1;

    int *input1 = new int[size1];
    for (int i = 0; i < size1; ++i)
        cin >> input1[i];

    int size2;
    cin >> size2;

    int *input2 = new int[size2];
    for (int i = 0; i < size2; ++i)
        cin >> input2[i];

    int outsize = 1 + max(size1, size2);
    int *output = new int[outsize];

    sumOfTwoArrays(input1, size1, input2, size2, output);
    for (int i = 0; i < outsize; ++i)
        cout << output[i] << " ";
    cout << endl;

    delete[] input1;
    delete[] input2;
    delete[] output;
    return 0;
}
