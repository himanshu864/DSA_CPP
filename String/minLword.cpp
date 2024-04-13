#include <iostream>
#include <cstring>
using namespace std;

void minLengthWord(char input[], char output[])
{
    int a, b;
    int min = 100000;
    for (int i = 0, j = 0; i <= strlen(input); i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            if ((i - j) < min)
            {
                min = i - j;
                a = j;
                b = i;
            }
            j = i + 1;
        }
    }
    int y = 0;
    for (int x = a; x < b; x++)
    {
        output[y] = input[x];
        y++;
    }
    output[y] = '\0';
}

int main()
{
    char ch[10000], output[10000];
    cout << "Enter a sentence(only one space): " << endl;
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
    return 0;
}
