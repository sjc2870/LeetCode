#!/usr/bin/env python3
#coding=utf-8
import string

class Solution:
    def reverseWords(self, s: str) -> str:
        #return ' '.join(word[::-1] for word in s.split(' '))
        # or
        return ' '.join(s[::-1].split(' ')[::-1])

so = Solution()
print(so.reverseWords("123456 789"))
