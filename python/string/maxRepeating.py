#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 1668 '''

class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        sup = word
        ret = 0
        
        while(sup in sequence):
            sup += word
            ret += 1
        return ret
