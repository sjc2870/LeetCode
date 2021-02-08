#!/usr/bin/env python3
#coding=utf-8

class Solution:
    def maximumTime(self, time: str) -> str:
        sup = list(time)

        for i, c in enumerate(sup):
            if i == 0 and c == '?':
                sup[0] = '2' if sup[1] in ['0', '1', '2', '3', '?'] else '1'
            elif i == 1:
                sup[1] = '3' if sup[0] == '2' else '9'
            elif i == 3:
                sup[3] = '5'
            elif i == 4:
                sup[4] = '9'
        return ''.join(sup)
