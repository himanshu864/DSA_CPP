#include <iostream>
using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

void initialize(struct rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct rectangle r)
{
    return r.length * r.breadth;
}

void changelen(struct rectangle *r, int l)
{
    r->length = l;
}

int main()
{
    struct rectangle r;
    initialize(&r, 10, 5);
    // cout << area(r) << endl;
    changelen(&r, 8);
    // cout << r.length << " " << r.breadth << endl;
    return 0;
}

// highest form of c programming