#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;
        // push char's into stack, increase count if (
        // don't let the count be negative, don't push )
        for (char c : s)
        {
            st.push(c);

            if (c == '(')
                count++;
            else if (c == ')')
            {
                if (count == 0)
                    st.pop();
                else
                    count--;
            }
        }

        // Remove access open brackets, if any (count +ve)
        // you have to remove from behind/reverse
        // stack is exactly what we needed
        // eg : ()((), here you can't remove first open bracket
        // else unvalid
        string ans = "";
        while (st.size())
        {
            if (st.top() == '(' && count > 0)
                count--;
            else
                ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "()(lee(t(c)o)de";
    cout << sol.minRemoveToMakeValid(s) << endl;
    return 0;
}
