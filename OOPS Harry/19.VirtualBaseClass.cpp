#include <iostream>
using namespace std;

/*
                 |---------> Class Test -------->|
Class Student ---                                 ---> Class Result
                 |--------> Class Sports ------->|
*/

// We solved the issue of getting roll no in result class twice (from both classes test and sports)

class Student
{
protected:
    int roll_no;

public:
    void set_number(int a)
    {
        roll_no = a;
    }
    void print_number()
    {
        cout << "Your Roll Number: " << roll_no << endl;
    }
};

class Test : virtual public Student
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }

    void print_marks()
    {
        cout << "Maths: " << maths << endl;
        cout << "Physics: " << physics << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(int a)
    {
        score = a;
    }
    void print_score()
    {
        cout << "Score: " << score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display()
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_score();
        cout << "Total: " << total << endl;
    }
};

int main()
{
    Result himanshu;
    himanshu.set_number(7);
    himanshu.set_marks(87.0, 94.0);
    himanshu.set_score(73);
    himanshu.display();
    return 0;
}

/*
           |---------> Class B -------->|
Class A ---                              ---> Class D
           |---------> Class C -------->|

If class A has a member named 'a', then B & C will also inherit A
Question is when D inherits from classes B & C, then it would take 2 instances of member 'a'

Virtual Base Class is solution of above case
To solve this what we should do is, make sure when someone in future takes a from both B and C, then check
if there's already another instance of 'a' bcoz there must be only 1 instance of 'a'
To do this, we declare A as virtual base classe while declaring classes B & C
We derived classes B & C with A as virtual base class

Syntax :
class B : virtual public A {};
class C : virtual public A {};

This saves us from duplication and ambiguity
When we made class B and class C, then we said that give me A as a virtual base class

What we did is, we made D indirectly from A such that we got only 1 copy of 'a' in class D
*/
