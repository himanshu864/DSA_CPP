#include <iostream>
using namespace std;

class Shop
{
    int counter;
    int ItemID[100];
    int ItemPrice[100];

public:
    Shop() // i used constructor, can also use initialize(void)
    {
        counter = 0;
    }
    void inputItem()
    {
        cout << "Enter Item ID: ";
        cin >> ItemID[counter];
        cout << "Enter Item Price: ";
        cin >> ItemPrice[counter];
        counter++;
    }
    void getPrice()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << (i + 1) << ". ID: " << ItemID[i] << "\t Price: " << ItemPrice[i] << endl;
        }
    }
};

int main()
{
    Shop dukaan;
    dukaan.inputItem();
    dukaan.inputItem();
    dukaan.getPrice();
    cout << "Size of object: " << sizeof(dukaan) << endl;
    return 0;
}

/*

c++ allocates memory very smartly
for each function, all variables have their own memory
while member functions, share one memory as they are common

*/
