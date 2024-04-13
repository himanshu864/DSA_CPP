#include <iostream>
using namespace std;

class rectangle
{
private:
    int length;
    int breadth;

public:
    // void initialize(int l, int b)
    rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    void changelen(int l)
    {
        length = l;
    }

    int getLength()
    {
        return length;
    }
};

int main()
{
    rectangle r(10, 5);
    // r.initialize(10, 5);
    cout << r.area() << endl;
    r.changelen(8);
    cout << r.getLength() << endl;
    return 0;
}
