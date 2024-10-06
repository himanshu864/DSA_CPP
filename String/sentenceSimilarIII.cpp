#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    vector<string> hashwords(string s)
    {
        vector<string> w;
        for (int i = 0; i < s.size(); i++)
        {
            string word = "";
            while (i < s.size() && s[i] != ' ')
                word += s[i++];
            w.push_back(word);
        }
        return w;
    }

    bool checkson(vector<string> w1, vector<string> w2)
    {
        // check if:
        // - w2 contains all words from w1,
        // - in same order,
        // - with just a few extra words in one gap
        // we shuold remove from both sides for special test cases, since only one gap
        int i = 0, j = 0;
        int ix = w1.size() - 1, jx = w2.size() - 1;
        bool free = true;
        while (i <= ix && j <= jx)
        {
            if (w1[i] == w2[j])
            {
                i++;
                j++;
            }
            else if (w1[ix] == w2[jx])
            {
                ix--;
                jx--;
            }
            else if (free)
            {
                free = false;
                while (j <= jx && w2[j] != w1[i])
                    j++;
            }
            else
                return false;
        }
        if (i <= ix)
            return false;
        return j > jx || free;
    }

public:
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1.size() == s2.size())
            return s1 == s2;

        // hash words with their order
        vector<string> w1 = hashwords(s1), w2 = hashwords(s2);

        return (s1.size() < s2.size() ? checkson(w1, w2) : checkson(w2, w1));
    }
};

int main()
{
    Solution sol;
    string s1 = "This baby";
    string s2 = "This is my baby";
    string s1 = "A";
    string s2 = "a A b A";
    cout << sol.areSentencesSimilar(s1, s2) << endl;
    return 0;
}

// https://leetcode.com/problems/sentence-similarity-iii/
