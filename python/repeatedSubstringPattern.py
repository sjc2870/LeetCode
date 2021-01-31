#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 459 算法思想见c++版本'''
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s+s)[1:-1]
