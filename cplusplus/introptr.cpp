#include <iostream>
using namespace std;

int main()
{
    // Arrays and Pointers
    int arr[5] = {5, 6, 7, 8, 9};
    int *p = &arr[0];

    cout << arr << endl;
    cout << &arr << endl;
    cout << p << endl;
    cout << arr[0] << " " << *arr << " " << 0 [arr] << " ";
    cout << *p << " " << p[0] << endl;
    p++;
    cout << *p << " ";
    cout << *(arr + 1) << " ";
    cout << 1 [arr] << endl;

    // Characters array and Pointers
    char ch[] = "Himanshu";
    cout << ch << endl;
    cout << ch[0] << " " << *ch << endl;

    char *cp = ch;
    // char *cp = &ch[0];
    cout << cp << endl;
    cout << *cp << endl;
    cp++;
    cout << cp << endl;
    cout << *cp << endl;

    // Character and pointers
    char c1 = 'a';
    char *p1 = &c1;
    cout << c1 << " " << *p1 << endl;
    c1++;
    cout << c1 << " " << *p1 << endl;
    // cout << p1 << endl;     // prints from 'a' till null character

    return 0;
}
