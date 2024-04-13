#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        string ans = "";
        vector<int> freq(26, 0);
        queue<int> q;
        for (int i = 0; i < s.size(); i++)
        {
            // push index in queue if first occurrences
            if (freq[s[i] - 'a']++ == 0)
                q.push(i);

            // pop all multiple occurrences from queue front until current unique or empty
            while (q.size() && freq[s[q.front()] - 'a'] > 1)
                q.pop();

            if (q.empty())
                ans += '#';
            else
                ans += s[q.front()];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "aabc";
    cout << sol.FirstNonRepeating(s) << endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
