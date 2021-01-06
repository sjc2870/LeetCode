#!/usr/bin/env python3

''' leetcode issue 1706
'''
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        ret = []
        for i in range(len(grid[0])):
            ret.append(self.dfs(grid, 0,i))
        return ret


    def dfs(self, grid, x, y):
        if(x == len(grid)):
            return y
        next_y = (y+1 if grid[x][y] == 1 else y-1)
        if(next_y < len(grid[0]) and next_y >= 0 and grid[x][y]+grid[x][next_y] != 0):
            return self.dfs(grid, x+1, next_y)
        return -1

