#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;

    s.push("malta");
    s.push("malik");
    s.push("abhishek");
    s.push("himanshu");

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "size: " << s.size() << endl;
    cout << "empty: " << s.empty() << endl;
    return 0;
}

// Last In First Out
