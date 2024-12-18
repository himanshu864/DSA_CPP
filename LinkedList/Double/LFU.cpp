#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key, val, freq;
    Node *prev, *next;
    Node(int key, int val, int freq, Node *prev = NULL, Node *next = NULL)
        : key(key), val(val), freq(freq), prev(prev), next(next) {}
};

class LFUCache
{
    int cap;
    int lowest_freq;
    unordered_map<int, Node *> cache;            // cache[key] -> node
    unordered_map<int, pair<Node *, Node *>> fd; // fd[freq] -> {MRU, LRU}

    // Add new node to DLL at given freq
    void add(Node *node)
    {
        int freq = node->freq;
        if (!fd.count(freq)) // if no DLL at that freq
        {
            Node *MRU = new Node(-1, -1, -1);
            Node *LRU = new Node(-1, -1, -1);
            MRU->next = LRU;
            LRU->prev = MRU;
            fd[freq] = {MRU, LRU};
        }
        lowest_freq = min(lowest_freq, freq);

        // add node to MRU's next
        Node *MRU = fd[freq].first;
        Node *first = MRU->next;
        MRU->next = node;
        node->prev = MRU;
        node->next = first;
        first->prev = node;
    }

    // Remove node from DLL + take update lowest_freq
    void rmv(Node *node)
    {
        Node *np = node->prev;
        Node *nn = node->next;
        np->next = nn;
        nn->prev = np;

        int freq = node->freq;
        if (freq == lowest_freq && np == fd[freq].first && nn == fd[freq].second)
            lowest_freq++;
    }

    // Increase freq of a node + update its position
    void update(Node *node)
    {
        rmv(node);
        node->freq += 1;
        add(node);
    }

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        lowest_freq = 1;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;

        Node *node = cache[key];
        update(node);
        return node->val;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            // first, delete LFU if max capacity
            if (cache.size() == cap)
            {
                Node *node = fd[lowest_freq].second->prev;
                rmv(node);
                cache.erase(node->key);
            }

            // add new node at freq = 1
            Node *node = new Node(key, value, 1);
            add(node);
            cache[key] = node;
        }
        else
        {
            Node *node = cache[key];
            node->val = value;
            update(node);
        }
    }
};

int main()
{
    vector<string> operations = {"LFUCache", "put", "put", "get", "get", "get", "put", "put", "get", "get", "get", "get"};
    vector<vector<int>> values = {{3}, {2, 2}, {1, 1}, {2}, {1}, {2}, {3, 3}, {4, 4}, {3}, {2}, {1}, {4}};

    LFUCache *cache = nullptr;
    for (size_t i = 0; i < operations.size(); ++i)
    {
        if (operations[i] == "LFUCache")
        {
            cache = new LFUCache(values[i][0]);
            cout << "Initialized LFUCache with capacity " << values[i][0] << '\n';
        }
        else if (operations[i] == "put")
        {
            cache->put(values[i][0], values[i][1]);
            cout << "Put (" << values[i][0] << ", " << values[i][1] << ")" << '\n';
        }
        else if (operations[i] == "get")
        {
            int result = cache->get(values[i][0]);
            cout << "Get (" << values[i][0] << ") -> " << result << '\n';
        }
    }
    delete cache;
    return 0;
}

// https://leetcode.com/problems/lfu-cache/
