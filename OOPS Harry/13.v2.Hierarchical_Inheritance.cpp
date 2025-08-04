#include <iostream>
#include <vector>
using namespace std;

class Person
{
    string name;

public:
    Person(string name)
    {
        this->name = name;
    }
    string get_name() const
    {
        return name;
    }
};

class Employee : public Person
{
    int emp_id;
    int salary;

protected:
    int get_salary() const
    {
        return salary;
    }

public:
    Employee(string my_name, int id, int salary) : Person(my_name)
    {
        emp_id = id;
        this->salary = salary;
    }
    int get_emp_id() const
    {
        return emp_id;
    }
};

class Programmer : public Person
{
    string lang;

public:
    Programmer(string name, string lang) : Person(name)
    {
        this->lang = lang;
    }
    string get_lang() const
    {
        return lang;
    }
};

int main()
{
    Employee emp("Himanshu", 123, 60000);
    cout << "Employee name:\t" << emp.get_name() << endl;
    cout << "Employee id:\t" << emp.get_emp_id() << endl;
    // cout << "Employee id:\t" << emp.get_salary() << endl;
    cout << endl;

    Programmer coder("Rishav", "JAVA");
    cout << "Programmer name:\t" << coder.get_name() << endl;
    cout << "Programmer lang:\t" << coder.get_lang() << endl;
    return 0;
}
