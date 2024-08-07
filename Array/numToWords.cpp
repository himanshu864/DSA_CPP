#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    const unordered_map<int, string> wordMap = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}};

    void helper(string &ans, int num, int multiplier)
    {
        if (num >= 1000)
            helper(ans, num / 1000, multiplier * 1000);

        int chunk = num % 1000;
        if (!chunk)
            return;

        int hundreds = chunk / 100;
        int tens = chunk % 100;

        if (hundreds)
            ans += " " + wordMap.at(hundreds) + " " + wordMap.at(100);

        if (tens < 20)
        {
            if (tens > 0)
                ans += " " + wordMap.at(tens);
        }
        else
        {
            int ten = tens / 10 * 10;
            int unit = tens % 10;
            if (ten)
                ans += " " + wordMap.at(ten);
            if (unit)
                ans += " " + wordMap.at(unit);
        }

        if (multiplier != 1)
            ans += " " + wordMap.at(multiplier);
    }

public:
    string numberToWords(int num)
    {
        if (!num)
            return wordMap.at(0);

        string result = "";
        helper(result, num, 1);
        return result.substr(1); // Remove leading space
    }
};

int main()
{
    Solution sol;
    int num = 12000050;
    cout << sol.numberToWords(num) << endl;
    return 0;
}
