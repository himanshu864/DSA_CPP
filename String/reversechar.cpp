#include <iostream>
using namespace std;

void reverseStr(char input[], int a, int b)
{
    while (a < b)
    {
        char temp = input[a];
        input[a] = input[b];
        input[b] = temp;
        a++;
        b--;
    }
}

void reverseStringWordWise(char input[])
{
    int n = 0;
    while (input[n] != '\0')
        n++;

    int a = 0;
    for (int i = 0; i <= n; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            reverseStr(input, a, i - 1);
            a = i + 1;
        }
    }
    reverseStr(input, 0, n - 1);
}

int main()
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
