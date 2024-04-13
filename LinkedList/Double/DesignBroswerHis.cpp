#include <iostream>
#include <string>
#include <vector>
using namespace std;

// create DLL Node class and use this data structure inside browser
class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string url) : data(url), next(nullptr), prev(nullptr) {}
};

class BrowserHistory
{
public:
    Node *tab;

    // Constructor
    BrowserHistory(string homepage)
    {
        tab = new Node(homepage);
    }

    // Add new node
    void visit(string url)
    {
        Node *temp = new Node(url);
        tab->next = temp;
        temp->prev = tab;
        tab = tab->next;
    }

    // Move steps back in history
    string back(int steps)
    {
        while (steps-- && tab->prev)
            tab = tab->prev;
        return tab->data;
    }

    // Move steps forward in history
    string forward(int steps)
    {
        while (steps-- && tab->next)
            tab = tab->next;
        return tab->data;
    }
};

int main()
{
    // Input
    vector<string> actions = {"BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"};
    vector<vector<string>> parameters = {{"leetcode.com"}, {"google.com"}, {"facebook.com"}, {"youtube.com"}, {"1"}, {"1"}, {"1"}, {"linkedin.com"}, {"2"}, {"2"}, {"7"}};

    // Output vector to store the results
    vector<string> output;
    BrowserHistory *browserHistory = nullptr;

    for (size_t i = 0; i < actions.size(); ++i)
    {
        if (actions[i] == "BrowserHistory")
        {
            browserHistory = new BrowserHistory(parameters[i][0]);
            output.push_back("null");
        }
        else if (actions[i] == "visit")
        {
            browserHistory->visit(parameters[i][0]);
            output.push_back("null");
        }
        else if (actions[i] == "back")
            output.push_back(browserHistory->back(stoi(parameters[i][0])));
        else if (actions[i] == "forward")
            output.push_back(browserHistory->forward(stoi(parameters[i][0])));
    }

    cout << "[";
    for (size_t i = 0; i < output.size(); ++i)
    {
        cout << "\"" << output[i] << "\"";
        if (i < output.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
    delete browserHistory;
    return 0;
}

// https://leetcode.com/problems/design-browser-history/
