#include <iostream>
using namespace std;

class NQueue
{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    NQueue(int n, int s)
    {
        arr = new int[s];
        front = new int[n]; // to update pop
        rear = new int[n];  // to update push
        next = new int[s];
        freespot = 0;

        for (int i = 0; i < n; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        for (int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        next[s - 1] = -1;
    }

    bool enqueue(int x, int m)
    {
        if (freespot == -1)
            return false;

        int index = freespot;
        freespot = next[index];
        arr[index] = x;

        if (front[m - 1] == -1) // if first element
            front[m - 1] = index;
        else // link current prev rear to current element
            next[rear[m - 1]] = index;

        next[index] = -1;
        rear[m - 1] = index;

        return true;
    }

    int dequeue(int m)
    {
        if (front[m - 1] == -1)
            return -1;

        int index = front[m - 1];   // element to be popped
        front[m - 1] = next[index]; // iterate front ahead
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main()
{
    NQueue nq(3, 10);
    cout << nq.enqueue(5, 1) << endl;
    cout << nq.enqueue(12, 2) << endl;
    cout << nq.enqueue(7, 1) << endl;
    cout << nq.dequeue(2) << endl;
    cout << nq.dequeue(1) << endl;
    return 0;
}

// https://www.codingninjas.com/studio/problems/n-queue-using-array_1170053
