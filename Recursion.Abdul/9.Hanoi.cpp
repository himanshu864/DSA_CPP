#include <iostream>
using namespace std;

void TOH(int n, string A, string B, string C)
{
    if (n == 0)
        return;
    TOH(n - 1, A, C, B);
    cout << "Move disk " << n << " from " << A << " to " << C << endl;
    TOH(n - 1, B, A, C);
}

int main()
{
    int n = 2;
    string scr = "A";
    string hlp = "B";
    string dest = "C";
    TOH(n, scr, hlp, dest);
    return 0;
}

// first solve shifting 1 and 2 no. of disks on paper
// for moving 3 disks we only need to follow 3 steps
// first move the 1st and 2nd disk from source(A) to helper(B) using Recursion (as you moved 2 disks)
// then manually move 3rd disk from source to destination(C) (as you moved only one disk)
// finally move the first two disks from helper(B) to destination(C) using recursion
// clearly we can follow the same procedure to move n disks using recursion
// there you go~ Don't try to remember the variables instead understand the concept

// Time Complexity: O(2^n)
