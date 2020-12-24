class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = []
        length = len(nums)
        for idx in range(length):
            dp.append(1)
            for j in range(idx):
                if(nums[j] < nums[idx]):
                    dp[idx] = max(dp[idx], dp[j]+1)

        return max(dp)
