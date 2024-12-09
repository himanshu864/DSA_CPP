from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        prefix = [1] * n # longest special subarray ending at index i
        for i in range(1, n):
            if (nums[i - 1] % 2) ^ (nums[i] % 2) == 1:
                prefix[i] += prefix[i - 1]
        
        # now that we have prefix
        # simply check whether given queries size is smaller than longest valid special subarray
        nq = len(queries)
        ans = [False] * nq
        for i in range(nq):
            ans[i] = prefix[queries[i][1]] >= (queries[i][1] - queries[i][0] + 1)
        return ans

def main():
    sol = Solution()
    nums = [4,3,1,6]
    queries = [[0,2],[2,3]]
    print(sol.isArraySpecial(nums, queries))

if __name__ == '__main__':
    main()