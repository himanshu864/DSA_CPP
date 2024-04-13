#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    vector<vector<int>> memory;
    for (string s : strs)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        memory.push_back(freq);
    }
    vector<bool> flag(strs.size(), true);
    for (int i = 0; i < strs.size(); i++)
    {
        if (flag[i])
        {
            vector<string> temp;
            temp.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (flag[j] && memory[j] == memory[i])
                {
                    temp.push_back(strs[j]);
                    flag[j] = false;
                }
            }
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (vector<string> v : groupAnagrams(strs))
    {
        for (string s : v)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}
