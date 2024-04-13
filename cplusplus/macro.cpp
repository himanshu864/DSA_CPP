#include <iostream>
#include <vector>
using namespace std;

// global variable: changable, hence not prefered
// double pi = 3.14;

#define STARTPLEASE int main() // only for demonstration

#define PI 3.14                    // object like
#define AREA(r) ((PI) * (r) * (r)) // chain and function-like macromacro

// multi-line macro
#define ONETOFIVE 1, \
                  2, \
                  3, \
                  4, \
                  5

STARTPLEASE
{
    int a = 7;
    // double area = pi * a * a;

    double area = AREA(a);
    cout << area << endl;

    vector<int> v = {ONETOFIVE};
    for (int i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}
