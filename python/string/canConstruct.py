#!/usr/bin/env python3
#coding=utf-8

import collections

''' leetcode issue 383'''
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        c1 = collections.Counter(magazine)
        c2 = collections.Counter(ransomNote)
        return c2 - c1
        '''
        sup = [0] * 26
        for c in magazine:
            sup[ord(c) - ord('a')] += 1
        for c in ransomNote:
            if(sup[ord(c) - ord('a')]):
                sup[ord(c) - ord('a')] -= 1
            else:
                return False
        return True
        '''

