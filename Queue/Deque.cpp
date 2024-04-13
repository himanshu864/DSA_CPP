#include <iostream>
#include <vector>
using namespace std;

// My rough circular deque. spent over 3-4 hours on this
// Somewhat optimized, notes/comments sucks
// 20-03-24 : 3:30AM
class MyCircularDeque
{
public:
    int *arr;
    int front;
    int rear;
    int n;
    int count;

    // Imagine two doubly ended queues

    // As we know: Rear is on right, and pushing at rear in deque is same as pushing in queue
    // Front is on left, and pushing at front in deque is completely the opposite

    // Create a circular array of size n and two pointers front and rear
    // and push value at front from right to left, and at rear from left to right
    // doing this we mirror

    // If one pointer leaves array (0 to n - 1), we circle it back to opposite end.
    // We need to initialize front and rear such that, front is just to the right of rear
    // To make sure deque is empty, and no unused space is left in array
    MyCircularDeque(int k)
    {
        arr = new int[k];
        front = 0;
        rear = k - 1;
        n = k;
        count = 0; // count is too OP
    }

    bool insertFront(int value) // Front only moves to left
    {
        if (count == n)
            return false;
        if (front-- == 0)
            front = n - 1;
        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) // Rear only moves to right
    {
        if (count == n)
            return false;
        if (++rear == n)
            rear = 0;
        arr[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() // Front increases
    {
        if (count == 0)
            return false;
        if (++front == n)
            front = 0;
        count--;
        return true;
    }

    bool deleteLast()
    {
        if (count == 0)
            return false;
        if (rear-- == 0)
            rear = n - 1;
        count--;
        return true;
    }

    int getFront()
    {
        if (count == 0)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (count == 0)
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == n; }
};

// better
class MyCircularDeque2
{
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int N;

public:
    MyCircularDeque2(int N) : arr(N, 0), size(0), N(N), front(0), rear(N - 1) {}

    bool insertFront(int value)
    {
        if (size == N)
            return false;
        front = (front - 1 + N) % N;
        arr[front] = value;
        ++size;

        return true;
    }

    bool insertLast(int value)
    {
        if (size == N)
            return false;
        rear = (rear + 1) % N;
        arr[rear] = value;
        ++size;

        return true;
    }

    bool deleteFront()
    {
        if (size == 0)
            return false;
        front = (front + 1) % N;
        --size;

        return true;
    }

    bool deleteLast()
    {
        if (size == 0)
            return false;
        rear = (rear - 1 + N) % N;
        --size;

        return true;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return size == 0; }
    bool isFull() { return size == N; }
};

int main()
{
    MyCircularDeque dq(3);

    dq.insertFront(10);
    dq.insertLast(30);
    cout << dq.getFront() << endl;
    cout << dq.deleteLast() << endl;

    return 0;
}
