from typing import List
import heapq

'''
Since we can only use two non-overlapping events to find max value.
We can sort the events based on starting time, and keep track of best non-overlapping value so far.
And can calculate ans by prev + curr value.

Use minHeap to sort past events based on ending.
'''

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        ans = 0
        prev = 0 # best non-overlapping prev value
        min_heap = [] # (ending, value)
        events.sort()
        for s, e, v in events:
            # once s > e time. We can use end value as best prev
            while(min_heap and s > min_heap[0][0]):
                prev = max(prev, heapq.heappop(min_heap)[1])
            ans = max(ans, prev + v)
            heapq.heappush(min_heap, (e, v))
        return ans
        
def main():
    sol = Solution()
    events = [[1,3,2],[4,5,2],[2,4,3]]
    print(sol.maxTwoEvents(events))

if __name__ == '__main__':
    main()
    
# https://leetcode.com/problems/two-best-non-overlapping-events/solutions/6124675/10-beautiful-lines-of-code-minheap-for-greedy-92-runtime-67-memory/
