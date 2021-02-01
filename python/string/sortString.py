#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 1370 '''

class Solution:
    def sortString(self, s: str) -> str:
        sup = [0] * 26
        for i in s:
            sup[ord(i) - ord('a')] += 1

        ret_len = 0
        ret = ''
        n = len(s)
        while ret_len < n:
            for i in range(26):
                if(sup[i]):
                    ret += chr(i + ord('a'))
                    ret_len += 1
                    sup[i]-=1
            for i in range(25,-1,-1):
                if(sup[i]):
                    ret += chr(i + ord('a'))
                    ret_len += 1
                    sup[i]-=1
        return ret

