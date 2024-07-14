#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

class Solution
{
public:
    string countOfAtoms(string formula)
    {
        // pre-map brackets with their multiplier
        int n = formula.size();
        stack<int> st;
        unordered_map<int, int> br;
        for (int i = 0; i < n; i++)
        {
            if (formula[i] == '(')
                st.push(i);
            if (formula[i] == ')')
            {
                i++;
                int count = 0;
                while (i < n && formula[i] >= '0' && formula[i] <= '9')
                    count = count * 10 + (formula[i++] - '0');

                br[st.top()] = count != 0 ? count : 1;
                st.pop();
                i--;
            }
        }

        map<string, int> atoms;
        st.push(1);
        for (int i = 0; i < n;)
        {
            // Could be multiple opening brackets
            while (formula[i] == '(')
                st.push(br[i++] * st.top());

            // Must be a capital letter
            string name = "";
            name += formula[i++];

            // Could be following name
            while (i < n && formula[i] >= 'a' && formula[i] <= 'z')
                name += formula[i++];

            // Could be number
            int count = 0;
            while (i < n && formula[i] >= '0' && formula[i] <= '9')
                count = count * 10 + (formula[i++] - '0');

            // Calculate answer
            atoms[name] += (count != 0 ? count : 1) * st.top();

            // Could be closing brackets with numbers, clean up
            while (i < n && formula[i] == ')')
            {
                st.pop();
                i++;
                while (i < n && formula[i] >= '0' && formula[i] <= '9')
                    i++;
            }
        }

        string ans = "";
        for (auto x : atoms)
            ans += x.first + (x.second != 1 ? to_string(x.second) : "");
        return ans;
    }
};

int main()
{
    Solution sol;
    string formula = "K4(ON(SO3)2)2";
    cout << sol.countOfAtoms(formula);
    return 0;
}

// https://leetcode.com/problems/number-of-atoms/
