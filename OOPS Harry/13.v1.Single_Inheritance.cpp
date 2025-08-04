#include <iostream>
#include <vector>
using namespace std;

class Person
{
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string get_name() const
    {
        return name;
    }
    int get_age() const
    {
        return age;
    }
};

class Employee : public Person
{
    int emp_id;

public:
    // Use member initialized list while inheriting to avoid creating default constructor
    Employee(string my_name, int my_age, int id) : Person(my_name, my_age)
    {
        emp_id = id;
    }
    int get_emp_id() const
    {
        return emp_id;
    }
};

int main()
{
    Employee emp("Himanshu", 22, 123);
    cout << "Employee id: " << emp.get_emp_id() << endl;
    cout << "Employee name: " << emp.get_name() << endl;
    cout << "Employee age: " << emp.get_age() << endl;
    return 0;
}
