#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Twitter
{
public:
    int priority;
    unordered_map<int, unordered_set<int>> follows;    // who is following who?
    unordered_map<int, vector<pair<int, int>>> tweets; // who posted what?

    Twitter()
    {
        priority = 1;
    }

    void postTweet(int userId, int tweetId)
    {
        follows[userId].insert(userId); // user follows himself
        tweets[userId].push_back({priority++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq; // most recent feed tracker

        // put all tweets of all followers of user, into priority queue. Sorted by priority, hence most to least recent
        for (auto follower : follows[userId])
            for (auto ptweet : tweets[follower])
                pq.push(ptweet);

        vector<int> ans;
        for (int i = 0; i < 10 && pq.size(); i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        follows[followerId].insert(followerId); // follower/user follows himself
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        // Prevent user from unfollowing themselves
        if (followerId != followeeId && follows[followerId].count(followeeId))
            follows[followerId].erase(followeeId);
    }
};

void printArray(vector<int> arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

// Test case
int main()
{
    Twitter *twitter = new Twitter();
    vector<string> methods = {"Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"};
    vector<vector<int>> params = {{}, {1, 5}, {1}, {1, 2}, {2, 6}, {1}, {1, 2}, {1}};
    twitter->postTweet(1, 5);
    printArray(twitter->getNewsFeed(1)); // 5
    twitter->follow(1, 2);
    twitter->postTweet(2, 6);
    printArray(twitter->getNewsFeed(1)); // 6 5
    twitter->unfollow(1, 2);
    printArray(twitter->getNewsFeed(1)); // 5
    delete twitter;
    return 0;
}

// https://leetcode.com/problems/design-twitter/
