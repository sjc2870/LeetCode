#!/usr/bin/env python3
#coding=utf-8
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        if(len(S) == 0):
            return ""
        if(len(S) == 1):
            return S
        sup = list(S)
        left = 0
        right = len(S) -1
        while left <= right:
            if not sup[left].isalpha():
                left += 1
                continue
            if not sup[right].isalpha():
                right -= 1
                continue
            else:
                sup[left], sup[right] = sup[right], sup[left]
                left += 1
                right -= 1

        return ''.join(sup)
