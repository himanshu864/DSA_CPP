#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sorting changing original
int findDuplicate2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
        if (nums[i - 1] == nums[i])
            return nums[i];
    return -1;
}

// Floydd's heir and tortoise + Linked List Cycle
int findDuplicate(vector<int> &nums)
{
    // think of it as a cyclic linked list
    // move fast pointer by 2 and slow by one
    int fast = nums[nums[0]];
    int slow = nums[0];
    while (fast != slow)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }
    // move head and intersection simultaneously
    int head = 0;
    while (head != fast)
    {
        head = nums[head];
        fast = nums[fast];
    }
    // there intersection will be the duplicate
    return head;
}

// guarenteed one duplicate : size = n + 1 : elements belong to - [1, N]
int main()
{
    vector<int> nums = {4, 2, 2, 1, 3};
    for (int i : nums)
        cout << i << " ";
    cout << endl;

    cout << "Duplicate: " << findDuplicate(nums) << endl;

    for (int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}

// https://leetcode.com/problems/find-the-duplicate-number/
