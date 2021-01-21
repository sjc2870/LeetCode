#!/usr/bin/env python3
#coding=utf-8
import numpy 

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        columns = len(grid[0])
        dp = numpy.zeros((rows, columns), dtype=int)

        dp[0][0] = grid[0][0]
        for i in range(rows):
            for j in range(columns):
                if(i == 0 and j > 0):
                    dp[0][j] = dp[0][j-1] + grid[0][j]
                elif(j == 0 and i > 0):
                    dp[i][0] = dp[i-1][0] + grid[i][0]
                elif (i > 0 and j > 0):
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

        return dp[rows-1][columns-1]
