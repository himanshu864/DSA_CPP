#include <iostream>
using namespace std;

class MyCircularQueue
{
public:
    int *arr;
    int n;
    int front;
    int rear;

    // Queue : pop <-- front .......... rear <-- push
    // Array : [ 0 | 1 | 2 ] 3 - 4 - 5- 6 - ...

    MyCircularQueue(int k)
    {
        arr = new int[k];
        n = k;
        // rear and front will exceed array of arr
        // but can refer index via modulo of size of array
        // hence, circular

        // if rear == front, here one element
        // if front exceeds rear after popping, stack empty
        // if their difference becomes size. stack full
        // this way we can create a queue without wasting any space inside array

        rear = -1;
        front = 0;
    }

    bool enQueue(int value)
    {
        if (rear - front + 1 == n)
            return false;
        arr[(++rear) % n] = value;
        return true;
    }

    bool deQueue()
    {
        if (rear + 1 == front)
            return false;
        front++;
        return true;
    }

    int Front() { return (rear + 1 == front) ? -1 : arr[front % n]; }

    int Rear() { return (rear + 1 == front) ? -1 : arr[rear % n]; }

    bool isEmpty() { return rear + 1 == front; }

    bool isFull() { return rear - front + 1 == n; }
};

int main()
{
    MyCircularQueue q(3);

    cout << "Empty: " << q.isEmpty() << endl;

    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;
    cout << q.enQueue(4) << endl;

    cout << "Full: " << q.isFull() << endl;
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.enQueue(4) << endl;

    cout << "Full: " << q.isFull() << endl;
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    return 0;
}

// https://leetcode.com/problems/design-circular-queue/
