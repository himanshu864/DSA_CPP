#include <iostream>
using namespace std;

class Employee
{
    // int count = 0; // here count is created every call, with 0 as its value

    // static data member:
    // created only once, all functions share copy, accessed only via class/function, lifetime = program
    static int count; // initialize outside class
    int id;

public:
    void setdata()
    {
        cout << "Enter ID: ";
        cin >> id;
        count++;
    }
    void getdata()
    {
        cout << count << ". Employee ID: " << id << endl;
    }

    // static functions inside class, can only access static members and other static funtions;
    static void getCount(void)
    {
        cout << "Current Count: " << count << endl;
        // cout << id << endl; // error
    }
};

int Employee::count; // Default value = 0

int main()
{
    Employee npc[3];

    for (int i = 0; i < 3; i++)
    {
        npc[i].setdata();
        npc[i].getdata();
        Employee::getCount();
        cout << endl;
    }

    return 0;
}
