#include <iostream>
using namespace std;

int main()
{
    int num, deno;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> deno;
    try
    {
        if (deno == 0)
        {
            throw deno;
        }
        cout << num / deno << endl;
    }
    catch (int ex)
    {
        cout << "Error: Division by " << ex << endl;
    }
    cout << "Code still works dude! " << endl;
    return 0;
}

/*
try
{
    // Code
    throw exception; // Throw an exception when a problem arises
}
catch ()
{
    // Code to handle exception
}
*/
