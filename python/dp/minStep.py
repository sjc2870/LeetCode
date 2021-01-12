''' leetcode issue 650
    thinking in c++ version
'''
import sys

class Solution:
    def minSteps(self, n: int) -> int:
        if(n == 1):
            return 0
        if(n == 2):
            return 2
        dp = [0] * (n+1)
        dp[1] = 0
        dp[2] =2
        for i in range(3,n+1):
            dp[i] = i
            for j in range(2,int(i/2)+1):
                if(i%j == 0):
                    dp[i] = min(dp[i], dp[j]+int(i/j))
        
        return dp[n]

so = Solution()
so.minSteps(int(sys.argv[1]))
