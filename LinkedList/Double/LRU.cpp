#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, val;
    Node *prev, *next;
    Node(int key, int val, Node *prev = NULL, Node *next = NULL)
    {
        this->key = key;
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};

// Elegant O(1) hashmap and Doubly Linked List Solution
class LRUCache
{
    int cap;
    unordered_map<int, Node *> cp; // cp[key] -> node
    Node *LRU, *MRU;               // MRU <-> LRU

    void add(Node *node) // append node to MRU's next
    {
        Node *first = MRU->next;
        MRU->next = node;
        node->prev = MRU;
        node->next = first;
        first->prev = node;
    }

    void rmv(Node *node) // connect node's prev and next
    {
        Node *np = node->prev;
        Node *nn = node->next;
        np->next = nn;
        nn->prev = np;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        LRU = new Node(0, 0);
        MRU = new Node(0, 0);
        MRU->next = LRU;
        LRU->prev = MRU;
    }

    int get(int key)
    {
        if (!cp.count(key))
            return -1;
        Node *node = cp[key];
        rmv(node);
        add(node);
        return node->val;
    }

    void put(int key, int value)
    {
        Node *node = new Node(key, value);
        if (!cp.count(key)) // inserting new node
        {
            add(node);
            cp[key] = node;
            if (cp.size() > cap)
            {
                Node *temp = LRU->prev;
                rmv(temp);
                cp.erase(temp->key);
            }
        }
        else // updating node
        {
            Node *temp = cp[key];
            rmv(temp);
            add(node);
            cp[key] = node;
        }
    }
};

// My hashmap and queue Solution
class LRUCache2
{
    int cap = 0;
    int index = 0;
    unordered_map<int, pair<int, int>> cache; // LRU Cache. Key-{value, last} Pairs
    queue<pair<int, int>> history;            // {key, last}

public:
    LRUCache2(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;

        history.push({key, index});
        cache[key].second = index++;
        return cache[key].first;
    }

    void put(int key, int value)
    {
        history.push({key, index});
        cache[key] = {value, index++};
        if (cache.count(key) && cache.size() <= cap)
            return;

        while (cache[history.front().first].second != history.front().second)
            history.pop();
        cache.erase(history.front().first);
        history.pop();
    }
};

int main()
{
    vector<string> operations = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};
    LRUCache *cache = nullptr;

    for (size_t i = 0; i < operations.size(); ++i)
    {
        if (operations[i] == "LRUCache")
        {
            cache = new LRUCache(values[i][0]);
            cout << "Initialized LRUCache with capacity: " << values[i][0] << '\n';
        }
        else if (operations[i] == "put")
        {
            cache->put(values[i][0], values[i][1]);
            cout << "Put(" << values[i][0] << ", " << values[i][1] << ")" << '\n';
        }
        else if (operations[i] == "get")
        {
            int result = cache->get(values[i][0]);
            cout << "Get(" << values[i][0] << ") = " << result << '\n';
        }
    }
    delete cache;
    return 0;
}

// https://leetcode.com/problems/lru-cache/
