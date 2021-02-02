#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 1374'''
import string

class Solution:
    def generateTheString(self, n: int) -> str:
        ret = 'a'
        while(n >= 26):
            n -= 2
            ret += "aa"
        ret += string.ascii_lowercase[1:n-1]
        return ret
