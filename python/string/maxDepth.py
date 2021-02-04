#!/usr/bin/env python3
#coding=utf-8

'''leetcode issue 1614'''
class Solution:
    def maxDepth(self, s: str) -> int:
        ret = 0
        depth = 0
        for c in s:
            if(c == '('):
                depth += 1
                ret = max(depth,ret)
            elif(c == ')'):
                depth -= 1

        return ret

