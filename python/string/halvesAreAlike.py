#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 1704 '''
class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        a = ['a','e','i','o','u','A','E','I','O','U']
        m = []
        n = []
        for i in list(s)[:len(list(s))//2]:
            if i in a:
                m.append(i)
        for j in list(s)[len(list(s))//2:]:
            if j in a:
                n.append(i)
        return bool(len(m) == len(n))
