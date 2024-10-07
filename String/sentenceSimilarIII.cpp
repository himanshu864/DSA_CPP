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

public:
    bool areSentencesSimilar(string s1, string s2)
    {
        if (s1.size() == s2.size())
            return s1 == s2;

        // split into words
        vector<string> w1 = hashwords(s1), w2 = hashwords(s2);

        // ensure w1 is smaller
        if (w1.size() > w2.size())
            swap(w1, w2);

        int n1 = w1.size();
        int i = 0, j = 0;

        // remove common prefix
        while (i < n1 && w1[i] == w2[i])
            i++;

        // remove common suffix
        while (j < n1 && w1[n1 - 1 - j] == w2[w2.size() - 1 - j])
            j++;

        // ensure that clears smaller sentence
        return i + j >= n1;
    }
};

int main()
{
    Solution sol;
    string s1 = "This baby";
    string s2 = "This is my baby";
    // string s1 = "A";
    // string s2 = "a A b A";
    cout << sol.areSentencesSimilar(s1, s2) << endl;
    return 0;
}

// https://leetcode.com/problems/sentence-similarity-iii/
