#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 3, b = 52, c = 523;
    cout << setw(3) << a << endl;
    cout << setw(3) << b << endl;
    cout << setw(3) << c << endl;
    cout << showpos << 43 << endl;

    float PI = 3.14;
    int num = 100;
    cout << setprecision(10) << PI << endl;
    cout << setbase(16) << num << endl; // sets base to 16
    return 0;
}

// manipulators in c++ to format output
// with and without arguments
