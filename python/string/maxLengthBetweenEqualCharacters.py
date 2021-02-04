#!/usr/bin/env python3
#coding=utf-8
import collections 

''' leetcode issue 1624'''

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        sup = collections.defaultdict(list)
        
        for c, idx in enumerate(s):
            sup[c].append(idx)

        ret = -1
        for k, v in sup.items():
            if len(v) >= 2:
                ret = max(v[-1]-v[0]-1, ret)
        return ret
