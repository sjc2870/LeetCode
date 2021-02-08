#!/usr/bin/env python3
#coding=utf-8
import string

class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s)-1
        if(j == -1):
            return True
        while(i <= j):
            if(not string.isalnum(s[i])):
                ++i
                continue
            elif(not string.isalnum(s[j])):
                ++j
                continue
            elif(not lower(s[i]) == lower(s[j])):
                return False
            ++i
            --j;
        return True

