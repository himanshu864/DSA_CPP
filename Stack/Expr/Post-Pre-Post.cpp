#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string postfixToPrefix(string s)
{
    stack<string> st;

    for (char c : s)
    {
        if (islower(c))
            st.push(string(1, c));
        else
        {
            string R = st.top();
            st.pop();
            string L = st.top();
            st.pop();
            st.push(c + L + R);
        }
    }
    return st.top();
}

string preToPost(string s)
{
    stack<string> st;
    reverse(s.begin(), s.end());
    for (char c : s)
    {
        if (islower(c))
            st.push(string(1, c));
        else
        {
            string L = st.top();
            st.pop();
            string R = st.top();
            st.pop();
            st.push(L + R + c);
        }
    }
    reverse(s.begin(), s.end());
    return st.top();
}

int main()
{
    string s = "-*ab/cd";

    s = preToPost(s);
    cout << s << endl;

    s = postfixToPrefix(s);
    cout << s << endl;
    return 0;
}
