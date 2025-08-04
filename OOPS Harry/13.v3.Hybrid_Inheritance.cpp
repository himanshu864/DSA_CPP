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

// use virtual inheritance to use single shared instance of base class Person
class Employee : public virtual Person
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

class Programmer : public virtual Person
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

class SDE : public Employee, public Programmer
{
    string role;

public:
    // Initialize virtual base class
    SDE(string my_name, int id, int my_salary, string my_lang, string my_role) : Person(my_name),
                                                                                 Employee(my_name, id, my_salary),
                                                                                 Programmer(my_name, my_lang)
    {
        role = my_role;
    }
    string get_role() const
    {
        return role;
    }
    int get_income() const
    {
        return get_salary() * (82) / 100;
    }
};

int main()
{
    SDE sde("Himanshu", 123, 60000, "C++", "Integration Head");
    cout << "SDE ID:\t" << sde.get_emp_id() << endl;
    cout << "SDE Name:\t" << sde.get_name() << endl;
    cout << "SDE Language:\t" << sde.get_lang() << endl;
    cout << "SDE Role:\t" << sde.get_role() << endl;
    cout << "SDE Income:\t" << sde.get_income() << endl;

    return 0;
}
