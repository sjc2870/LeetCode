''' leetcode 837 issue
    think in c++ version 
'''

class Solution(object):
    def new21Game(self, N, K, W):
        """
        :type N: int
        :type K: int
        :type W: int
        :rtype: float
        """
        if(K == 0):
            return 1.0
        dp = []
        dp = [0.0] * (K + W)
        for i in range(K+W):
            if K <= i <= N:
                dp[i] = 1.0
        dp[K-1] = float((N-K+1))/W
        for i in range(K-2,-1,-1):
            dp[i] = dp[i+1] + (dp[i+1] - dp[i+W+1])/W
        return dp[0]
