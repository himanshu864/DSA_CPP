#include <iostream>
using namespace std;

class idk
{
    // private:

public:
    int length = 0;
    int breadth = 0;

    int area()
    {
        return length * breadth;
    }

    int peri()
    {
        return 2 * (length + breadth);
    }
};

int main()
{
    idk r;
    r.length = 5; // only accessable when l and b are public
    r.breadth = 3;
    cout << r.area() << " " << r.peri() << endl;
    return 0;
}

// monolithic program is when everything inside the main function
// modular programming is when functions are used;
// structures are used to group related datamembers under one name (C)
// Object oriention is write the data members and member functions together at one place (C++)
