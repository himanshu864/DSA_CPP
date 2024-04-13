#include <iostream>
using namespace std;

typedef struct employee
{
    int eid;
    char grade;
    float salary;
} ep;

union money
{
    int rice;
    char grade;
    float salary;
};

int main()
{
    // typedef is used to rename structure
    cout << " > Typedef: " << endl;
    ep harry;
    harry.eid = 1;
    harry.grade = 'a';
    cout << harry.eid << " " << harry.grade << endl;

    cout << " > Union: " << endl;
    money lisa;
    lisa.rice = 3;
    cout << lisa.rice << endl;
    lisa.grade = 'c';
    cout << lisa.rice << " " << lisa.grade << endl;

    cout << " > Enum: " << endl;
    enum Meal
    {
        breakfast,
        lunch,
        dinner
    };
    cout << breakfast << " " << lunch << " " << dinner << endl;
    Meal xyz = lunch;
    cout << xyz << endl;
    return 0;
}

// union is very memory efficient when using similar data types
// union only shows one value at a time, and overrides when new data is inputed

// enum to make program more readable ig
// Meal itself becomes a datatype lol
