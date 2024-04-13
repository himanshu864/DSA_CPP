#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;
    q.push("himanshu"); // first
    q.push("malik");
    q.push("goli"); // last

    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    q.pop();
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    q.push("abhishek"); // now last
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;

    cout << "size: " << q.size() << endl;
    cout << "empty: " << q.empty() << endl;

    return 0;
}

// Queue: First In First Out
