# Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/description/

# Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

# Solution, Time and Space Complexity: Dynamic Programming, O(n*sum) where n is the number of elements in the array and sum is the total sum of all elements in the array.

class Solution:
       
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        if(totalSum%2): return False
        return subsetSumK(nums, totalSum//2)

def subsetSumK(nums, targetSum):

        n = len(nums)
        
        dp = [[False] * (targetSum + 1) for _ in range(len(nums))]
        for i in range(n):
            dp[i][0] = True
            
        if nums[0] <= targetSum:
            dp[0][nums[0]] = True
            
        for index in range(n):
            for target in range(1, targetSum + 1):
                notTaken = dp[index - 1][target]
                taken = False
                if nums[index] <= target:
                    taken = dp[index - 1][target - nums[index]]
                dp[index][target] = notTaken or taken
        
        return dp[n - 1][targetSum]