from typing import List

# O(N) & O(N)
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)

        # give more candies if child has higher rating than left neighbor
        left = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                left[i] = left[i - 1] + 1
        
        # give more candies if child has higher rating than right neighbor
        right = [1] * n
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right[i] = right[i + 1] + 1
                
        ans = 0
        for i in range(n):
            ans += max(left[i], right[i]) 
        return ans

def main():
    sol = Solution()
    ratings = [1,2,3,1]
    print(sol.candy(ratings))

if __name__ == '__main__':
    main()

# https://leetcode.com/problems/candy/
