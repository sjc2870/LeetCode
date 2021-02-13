#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 448'''

class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ret = []
        
        for i in nums:
            x = (i-1) % n
            nums[x] += n

        for idx, num in enumerate(nums):
            if nums[idx] <= n:
                ret.append(idx+1)
        return ret
