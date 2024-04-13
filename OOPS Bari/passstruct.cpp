#include <iostream>
using namespace std;

struct rect
{
    int length;
    int width;
};

// pass by value, use (&r2) for referencing
int area(struct rect r2)
{
    r2.width++;
    return r2.length * r2.width;
}

// call by address
void func(struct rect *p, int l)
{
    p->length = l;
}

struct okay // structure with array
{
    int arr[5];
    int n;
};

void temp(struct okay y) // arrays inside a structure can be passed by value
{
    y.arr[0] = y.n; // changes do not reflect
}

int main()
{
    rect r = {10, 5};
    cout << "Area with extra width: " << area(r) << endl;
    cout << r.length << " " << r.width << endl;

    rect rc = {5, 4};
    func(&rc, 8);
    cout << rc.length << " " << rc.width << endl;

    okay x = {{1, 2, 3, 4, 5}, 10};
    temp(x);
    cout << x.arr[0] << " " << x.n << endl;

    return 0;
}
