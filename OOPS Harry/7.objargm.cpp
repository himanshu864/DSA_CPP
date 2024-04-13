#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    // we can also pass objects of same/different class as arguments
    void setDatabySum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void printVal()
    {
        cout << "Your complex No: " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    complex c1, c2, c3;

    c1.setData(1, 2);
    c1.printVal();

    c2.setData(3, 4);
    c2.printVal();

    c3.setDatabySum(c1, c2);
    c3.printVal();

    return 0;
}
