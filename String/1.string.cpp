#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    char ch[100];
    cout << "Enter name: ";
    cin.getline(ch, 100);
    cout << ch << endl;
    cout << "Size: " << strlen(ch) << endl;

    string s;
    cout << "Enter quote: ";
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    s += " bitch";
    cout << s << endl;
    cout << "Length: " << s.size();
    return 0;
}

// transform(s.begin(), s.end(), s.begin(), ::tolower); to convert entire string to lower cases
// s.size(); s.push_back('x'); s.pop_back(); s += "nice"; insert, erase, find, at, etc
// s.substr(pos, len), charAt()
// char [] ch = s.toCharArray(); to convert string into char arr
