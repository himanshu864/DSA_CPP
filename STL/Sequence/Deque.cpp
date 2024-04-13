#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq = {1, 2, 3};

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    dq.push_front(5);
    dq.push_back(4);

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    dq.pop_front();

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    cout << "at(2): " << dq.at(2) << endl;
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Empty: " << dq.empty() << endl;

    dq.erase(dq.begin() + 1, dq.begin() + 2);

    for (int i : dq)
        cout << i << " ";
    cout << endl;

    return 0;
}

// Double-ended queue: Deque: insert/delete from both ends
