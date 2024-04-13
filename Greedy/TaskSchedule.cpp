#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // just need freq of tasks in decreasing order
        vector<int> freq(26, 0);
        for (char X : tasks)
            freq[X - 'A']++;
        sort(freq.begin(), freq.end(), greater<int>());

        int idles = (freq[0] - 1) * n;
        // minus 1 as no need of idles after last occurrence

        for (int i = 1; i < 26; i++)
            idles -= min(freq[i], freq[0] - 1);
        // min with freq[0] - 1 as no further idles can be filled

        return tasks.size() + max(0, idles);
        // max with 0 as idles can not be negative
    }
};

/*

Tasks = {AAAABBBCCDDE} || Decreasingly sorted to understand:

Here, with A occuring 4 times, it requires atleast n space b/w any two of task

A _ _ A _ _ A _ _ A         || A - 4
-->idles = (maxfreq - 1) * n = (4 - 1) * 2 = 6

Notice Remaining tasks have freq less then this and are in decreasing order
Hence, no further idles would be created if filled efficiently.
For example next B also has max occurrences. After filling at idles:

A B _ A B _ A B _ A B       || B - 4
Notice even through B exceeded A, no further idles were created.
And only 3 idles were filled, out of 4 B's.

Therefore, we just need to fill the tasks such that no idles remain
And Minimum interval will be : total no. of tasks - remaining idles

A B C A B C A B _ A B       || C - 2
A B C A B C A B D A B D     || D - 2
A B C E A B C A B D A B D   || E - 1
Also notice once all idles have been filled
We start scheduling further tasks b/w first two A's to avoid idles

*/

int main()
{
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'D', 'D', 'E'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl;
    return 0;
}

// https://leetcode.com/problems/task-scheduler/
