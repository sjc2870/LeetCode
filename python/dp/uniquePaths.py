#!/usr/bin/env python3
#coding=utf-8

import numpy as np
''' leetcode issue 62'''
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp = int[3][4]
        dp = np.zeros((m, n), dtype=int)
        for i in range(m):
            for j in range(n):
                if(i == 0 or j == 0):
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]

so = Solution()
print(so.uniquePaths(3,7))
