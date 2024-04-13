#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// O(N) Space Complexity using stack
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int j = 0;
        for (int i : pushed)
        {
            st.push(i);
            while (st.size() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

// O(1) space complexity solution : Just change given array instead of creating extra stack
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int i = 0, j = 0;
    for (int x : pushed)
    {
        pushed[i++] = x;
        while (i && pushed[i - 1] == popped[j])
            i--, j++;
    }
    return i == 0;
}

int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    Solution sol;
    cout << sol.validateStackSequences(pushed, popped) << endl;

    cout << validateStackSequences(pushed, popped) << endl;

    return 0;
}

// https://leetcode.com/problems/validate-stack-sequences/
