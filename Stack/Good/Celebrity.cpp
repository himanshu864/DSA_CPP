#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(int A, int B)
{
    if (A == 0 && B == 2)
        return true;
    if (A == 0 && B == 3)
        return true;
    if (A == 1 && B == 2)
        return true;
    if (A == 3 && B == 0)
        return true;
    if (A == 3 && B == 1)
        return true;
    if (A == 3 && B == 2)
        return true;
    return false;
}

/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// my brute
// int findCelebrity(int n)
// {
//     vector<bool> might(n, true);
//     for (int i = 0; i < n; i++)
//     {
//         if (!might[i])
//             continue;
//         for (int j = 0; j < n; j++)
//         {
//             if (j == i)
//                 continue;
//             if (knows(i, j))
//             {
//                 might[i] = false;
//                 break;
//             }
//         }
//         if (might[i])
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (j == i)
//                     continue;
//                 if (!knows(j, i))
//                     return -1;
//             }
//             return i;
//         }
//     }
//     return -1;
// }

// basically an eliminating process using stacks
int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        if (knows(A, B)) // if A knows B, A can not be the celebrity
            st.push(B);
        else // if A doesn't know B, B can not be the celebrity
            st.push(A);
    }
    int cel = st.top();
    for (int i = 0; i < n; i++)
    {
        if (i == cel)
            continue;
        if (!knows(i, cel) || knows(cel, i))
            return -1;
    }
    return cel;
}

int main()
{
    int n = 4;
    cout << findCelebrity(n) << endl;
    return 0;
}
