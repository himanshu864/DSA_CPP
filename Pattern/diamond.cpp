#include <iostream>
using namespace std;

void printcell(int r, int c, int s)
{
    for (int l = 1; l <= r; l++)
    {
        for (int i = 1; i <= s; i++)
        {
            for (int k = 1; k <= c; k++)
            {
                for (int j = 1; j <= s - i; j++)
                {
                    cout << "e";
                }
                cout << "/";
                for (int j = 1; j < i; j++)
                {
                    cout << "oo";
                }
                cout << "\\";
                for (int j = 1; j <= s - i; j++)
                {
                    cout << "e";
                }
            }
            cout << endl;
        }
        for (int i = s; i >= 1; i--)
        {
            for (int k = 1; k <= c; k++)
            {
                for (int j = 1; j <= s - i; j++)
                {
                    cout << "e";
                }
                cout << "\\";
                for (int j = 1; j < i; j++)
                {
                    cout << "oo";
                }
                cout << "/";
                for (int j = 1; j <= s - i; j++)
                {
                    cout << "e";
                }
            }
            cout << endl;
        }
    }
}

int main()
{
    int rows;
    cin >> rows;
    int cols;
    cin >> cols;
    int n;
    cin >> n;
    printcell(rows, cols, n);
    return 0;
}

/*

/\
\/

e/\e
/oo\
\oo/
e\/e

ee/\ee
e/oo\e
/oooo\
\oooo/
e\oo/e
ee\/ee

e/\ee/\e
/oo\/oo\
\oo/\oo/
e\/ee\/e

*/