#include <iostream>
using namespace std;

class employee
{
private:
    int a = 0, b = 0, c = 0;

public:
    int d = 0, e = 0;
    void setdata(int a, int b, int c); // only need to a, b, and c as they are private
    void getdata(int a, int b, int c)
    {
        cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    }
};

void employee::setdata(int a, int b, int c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

int main()
{
    employee manoj;
    manoj.d = 5;
    manoj.e = 7;
    // manoj.a = 8;
    manoj.setdata(1, 2, 3);
    manoj.getdata(1, 2, 3);
    return 0;
}

// class are extensions of structures as they have methods and properties
// better security with private, public and protected members
// structures are typedef while classes are user-defined
