#include <iostream>
using namespace std;

struct RECTANGLE
{
    int length;
    int breadth;
} r2; // can also declare here

struct card
{
    int face;
    int shape;
    int color;
};

struct RECTANGLE r3 = {4, 9}; // and here for global access

int main()
{
    // declare, initialize and access
    struct RECTANGLE r = {10, 5};
    r.length = 20;
    r.breadth = 8;
    cout << "Area: " << r.length * r.breadth << endl;

    // array of structures
    struct card deck[52];
    deck[0] = {2, 3, 1};
    deck[1] = {1, 0, 0};
    cout << deck[0].color << " " << deck[1].face << endl;

    // size of structure is sum of all the members in it
    cout << "size of deck structure array: " << sizeof(deck) << endl;
    cout << "size of rectangle: " << sizeof(r2) << endl;

    // pointers in structures
    RECTANGLE *p2 = &r3;
    p2->breadth = 20;
    cout << (*p2).breadth << endl;

    // create a structure in heap using pointers
    RECTANGLE *p = new RECTANGLE; // no need for struct in cpp
    (*p).length = 15;
    p->breadth = 7; // also access pointers in cpp
    cout << p->length << " " << p->breadth << endl;
    return 0;
}

// structures are collection of similar/non-similar data members under one name
