#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 674'''
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        cur = 1
        ret = 0

        if(len(nums) == 0):
            return 0
        for i in range(1, len(nums)):
            if(nums[i] > nums[i-1]):
                cur += 1
            else:
                ret = max(ret, cur)
                cur = 1
        
        ret = max(ret, cur)
        return ret
