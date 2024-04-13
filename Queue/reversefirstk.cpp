#include <bits/stdc++.h>
using namespace std;

// Too easy using stack
// and can apply use same helper function to reverse entire queue for k == q.size()

// reverse first k elements using recursion and push them to rear
// for k = 3, [1, 2, 3, 4, 5] becomes :
// 4 5 3 2 1
// Then simply push and pop remaining un-reversed element to back
void helper(queue<int> &q, int k, int i)
{
    if (i == k)
        return;

    int temp = q.front();
    q.pop();
    helper(q, k, i + 1);
    q.push(temp);
}

queue<int> reverseElements(queue<int> q, int k)
{
    if (k < 2 || q.size() < 2)
        return q;

    helper(q, k, 0);

    for (int x = k; x < q.size(); x++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    q = reverseElements(q, k);
    while (q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/reverse-first-k-elements-of-queue_982771
