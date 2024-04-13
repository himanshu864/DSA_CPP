#include <iostream>
#include <string>
using namespace std;

class binary
{
    // private:
    string s;
    void check(void);

public:
    void read(void);
    void ones(void);
    void print(void);
};

void binary::read(void)
{
    cout << "Enter a binary number: ";
    cin >> s;
    check();
}

void binary::check(void)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Error!" << endl;
            exit(0);
        }
    }
}

void binary::ones(void)
{
    check();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
}

void binary::print(void)
{
    cout << s << endl;
}

int main()
{
    binary b;
    // b.check(); // user can't use this private function
    b.read();
    b.print();
    b.ones();
    b.print();
    return 0;
}

// class are extensions of structures as they have methods and properties
// better security with private, public and protected members
// structures are typedef while classes are user-defined
