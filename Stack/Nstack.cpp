#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Just understand how next[S] works:
next is initialized with next free indices in parallel to array
while last element of next will be -1, as no more empty space
Example of an array of size S = 6 : next[6] = [1, 2, 3, 4, 5, -1];
while freespot contains first empty space in array

While pushing,
update arr at index [freespot] if empty space exists
update freespot next empty space by referring next[freespot];
and most importantly : Update that next to index of prev top element of that stack by referring to top[m - 1]
This is necessary for popping this element in future and this also updates next to -1 if top was empty
Finally update top of mth stack to original freespot, as that is now the index of x

For popping,
we need to revert top, next and freespot to back to before we pushed that element
Firstly store index of top of that stack by referring to top[m - 1]
then update top[m - 1] to the index of prev top element of that stack,
    which we stored inside next at the same index as that of the element being popped (stored top[m - 1])
update that next index to current freespot
and current freespot to the index of element being popped, as it is empty now

*/

class NStack
{
public:
    int *arr;     // actually store data
    int *top;     // contains top indices of all N stacks
    int *next;    // either contains next free spot or index of prev top element after push
    int freespot; // index where future element will be placed

    NStack(int N, int S)
    {
        arr = new int[S];
        next = new int[S];
        top = new int[N];

        freespot = 0; // Place first element at 0

        for (int i = 0; i < S - 1; i++) // then 1, 2, 3 ... S - 1
            next[i] = i + 1;
        next[S - 1] = -1; // Last next will contain -1, as no push possible after that

        for (int i = 0; i < N; i++)
            top[i] = -1;
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
            return false;

        int index = freespot; // freespot contains index for x
        arr[index] = x;
        freespot = next[index];   // next[index] becomes next freespot
        next[index] = top[m - 1]; // next will contain index of prev top
        top[m - 1] = index;       // while top contains current index

        return true;
    }

    int pop(int m)
    {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];   // element that will pop
        top[m - 1] = next[index]; // that stack's top now contain index of prev top
        next[index] = freespot;   // the current freespot will become next freespot that index
        freespot = index;         // as the index is free now
        return arr[index];
    }
};

int main()
{
    NStack st(3, 6);
    // cout << (st.push(10, 1) ? "True" : "False") << endl;
    // cout << (st.push(20, 1) ? "True" : "False") << endl;
    // cout << (st.push(30, 2) ? "True" : "False") << endl;
    // cout << st.pop(1) << endl;
    // cout << st.pop(2) << endl;

    cout << st.pop(2) << endl;
    cout << (st.push(8, 2) ? "True" : "False") << endl;
    cout << (st.push(1, 2) ? "True" : "False") << endl;
    cout << (st.push(25, 2) ? "True" : "False") << endl;
    cout << (st.push(41, 3) ? "True" : "False") << endl;
    cout << (st.push(20, 2) ? "True" : "False") << endl;
    cout << (st.push(17, 2) ? "True" : "False") << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(2) << endl;
    cout << st.pop(2) << endl;

    return 0;
}

// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271
