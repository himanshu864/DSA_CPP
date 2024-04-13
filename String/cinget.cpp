#include <iostream>
using namespace std;

int main()
{
    char ch[100];
    cin.getline(ch, 100, '$');

    int x = 0, y = 0, z = 0;
    for (int i = 0; ch[i] != '$' && i < 100; i++)
    {
        if (ch[i] >= 'a' && ch[i] <= 'z')
            x++;
        else if (ch[i] >= '0' && ch[i] <= '9')
            y++;
        else if (ch[i] == ' ' || ch[i] == '\n' || ch[i] == '\t')
            z++;
    }
    cout << x << " " << y << " " << z;
    return 0;
}

// for (char ch = cin.get(); ch != '$'; ch = cin.get())
// {
//     if (ch >= 'a' && ch <= 'z')
//         x++;
//     else if (ch >= '0' && ch <= '9')
//         y++;
//     else if (ch == ' ' || ch == '\n' || ch == '\t')
//         z++;
// }
