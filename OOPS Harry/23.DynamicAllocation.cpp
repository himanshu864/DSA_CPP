#include <iostream>
#include <vector>
using namespace std;

/*

## Purpose:
- To allocate memory dynamically for single variables or arrays.

## Mechanism:
- When new is used, it requests a block of memory from the heap that is large enough to store the specified data type or object.

## Return Value:
- new returns a pointer to the beginning of the newly allocated memory block.
- This pointer is then used to access and manipulate the allocated data.

## Initialization:
- For objects, new automatically calls the constructor of the class to initialize the allocated memory.
- For built-in types, it can optionally initialize them.

## Memory Management:
- When memory is allocated with new, it is the programmer's responsibility to deallocate it using the delete operator
    (or delete[] for arrays) when it is no longer needed.
- Failure to do so leads to memory leaks.

*/

class Complex
{
    int a, b;

public:
    void set_data(int x, int y)
    {
        a = x;
        b = y;
    }
    void get_data()
    {
        cout << a << " + i" << b << endl;
    }
};

int main()
{
    // ----------  Pointers ----------
    int a = 5;
    int *p = &a;
    cout << *p << endl;

    // ----------  Heap Allocation ----------
    int *ptr = new int(40);
    // float *ptr = new float(8.45);
    cout << *ptr << endl;
    delete ptr;

    // ----------  Array ----------
    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    for (int i = 0; i < 3; i++)
        cout << *(arr + i) << " ";
    cout << endl;
    delete[] arr;

    // ----------  Pointers to Objects ----------
    // Complex cmp;
    // Complex *cpt = &cmp;
    Complex *cpt = new Complex;
    (*cpt).set_data(3, 4);
    cpt->get_data();
    delete cpt;

    // ----------  Array of Objects ----------
    int size = 3;
    Complex *acp = new Complex[size];
    for (int i = 1; i <= size; i++)
    {
        (*(acp + i)).set_data(i, 2 * i);
        (acp + i)->get_data();
        // acp->set_data(i, 2 * i);
        // acp->get_data();
        // acp++;
    }
    delete[] acp;

    return 0;
}
