#!/usr/bin/env python3
#coding=utf-8
import numpy as np
'''leetcode issue 1143'''

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        rows = len(text1)+1
        columns = len(text2)+1
        dp = np.zeros((rows, columns), int)
        for i in range(rows):
            for j in range(columns):
                if(i == 0 or j == 0):
                    dp[i][j] = 0
                else:
                    if(text1[i-1] == text2[j-1]):
                        dp[i][j] = dp[i-1][j-1] + 1
                    else:
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[rows-1][columns-1]
        
so = Solution()
ret = so.longestCommonSubsequence("abc", "abc")
print(ret)
