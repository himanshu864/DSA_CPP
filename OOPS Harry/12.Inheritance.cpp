#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world" << endl;
    return 0;
}

/*

##Inheritance:
 - Reusablity : to follow DRY principle : Don't Repeat Yourself
 - We can reuse a class and add Additional features to it
 - Reusing already tested and debugged class saves time, money and effort

## What is Inheritance:
 - Brings concept of Reusability in c++
 - can reuse properties of an existing class by inheriting it
 - the existing class is called BASE class
 - the new class inherited is called DERIVED class

##Types of inheritance:
 - Single
 - Multiple
 - Multilevel
 - Hybrid

## Single Inheritance:
 - Derived class with only one Base class
 eg : Employee derives Programmer : A --> B
 - B Extends work of A class

## Multiple Inheritance:
 - A class with Derived from more than one Base class
 eg : Programmer(C) acts as an Employee(A) as well as Assistant(B) for technical stuff
 - C inherits all properties of A and B : A --> C <-- B

## Hierarchical Inheritance:
 - Several classes Derived from one Base class
 eg : A programmer(B) and A manager(C) are both eccentially employees(A) of a company
 - Both B and C are derived from A : B <-- A --> C

## Multilevel Inheritance:
 - deriving a class from an already derived class
 Eg : Mammals(B) are animals(A) with more, and humans(C) are mammals with more
 - B is derived from A, and C is derived from B : A --> B --> C

## Hybrid Inheritance:
 - Combination of Single, Multiple, Hierarchical and Multilevel inherihence
 Eg : Animal(A) derives Mammals(B) and Birds(C), which Bat(D) is derived from both Mammals and Birds
 -      A
       / \
      B   C
       \ /
        D
    A derives B and C (heirarchical); B and C derive D (Multiple); A derive B which derive C (Multilevel); D is derived from A(Single)



*/