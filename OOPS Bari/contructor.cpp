#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle() // default constructure
    {
        length = 1;
        breadth = 1;
    }
    Rectangle(int l, int b); // parametrised constructure

    int area(); // facilitatures
    int perimeter();

    int getlength() { return length; } // accesser
    void setLength(int l)              // mutator
    {
        length = l;
    }
    ~Rectangle(); // destructure
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle()
{
}

int main()
{
    Rectangle r(5, 3);
    cout << r.area() << " " << r.perimeter() << endl;
    r.setLength(8);
    cout << r.getlength();
    return 0;
}

// Constructors are automatically called, when an object is created
// here by using contructures, no need to specificially initialize.
