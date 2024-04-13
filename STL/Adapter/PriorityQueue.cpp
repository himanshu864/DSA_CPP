#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap : largest element gets highest priority
    priority_queue<int> maxi; // default is max

    maxi.push(4);
    maxi.push(2);
    maxi.push(3);
    maxi.push(5);

    int n = maxi.size();
    cout << "Size of maxi: " << n << endl;

    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop(); // keeps popping element with highest priority
    }
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> mini;

    mini.push(4);
    mini.push(2);
    mini.push(3);
    mini.push(5);

    int m = mini.size();
    cout << "Size of mini: " << m << endl;

    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "is empty: " << mini.empty() << endl;

    return 0;
}
