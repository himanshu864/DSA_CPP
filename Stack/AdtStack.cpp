#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (s.size())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n%d", s.empty());
    return 0;
}

/*
## STACK : Linear Data structure where insertion and deletion of element takes place at the same end (top)
## LIFO : Follows Last-In First-Out method : Last element in will come out first

Notice : If we place balls 1, 2, and 3 in a stack container. They will come out as 3, 2, and then 1
Hence, Reversed!

Recursion uses an internal stack to perform call and return time operations, which compiler takes care of
When converting into iterative loops. Programmer might need to implement a stack by himself (programmers stack)

## ADT Stack : Abstract Data Type
#Data:
    1. Space for storing elements
    2. Top pointer

#Operation:
    1. Push(x)
    2. Pop()
    3. Top()
    4. Empty()
    5. Size()

*/