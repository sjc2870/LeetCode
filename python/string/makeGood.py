#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 1544 '''

class Solution:
    def makeGood(self, s: str) -> str:
        stack=[]

        for c in s:
            if stack:
                if(abs(ord(c) - ord(stack[-1])) != 32):
                    stack.append(c)
                else:
                    stack.pop(c)
            else:
                stack.append(c)
        return str(stack)
