#!/usr/bin/env python3
#coding=utf-8

import random
import string

class Solution:
    str1 = "abcdefghijklmnopqrstuvwxyz"
    @property
    def next_char(self):
        return random.choice(string.ascii_letters).lower()
    def modifyString(self, s: str) -> str:
        if(len(s) == 1 and s[0] == '?'):
            return 'a'
        s = list(s)
        for i in range(len(s)):
            if(s[i] == '?'):
                s[i] = self.next_char
                if(i == 0):
                    while(s[i] == s[i+1]):
                        s[i] = self.next_char
                elif(i == len(s)-1):
                    while(s[i]== s[i-1]):
                        s[i] = self.next_char
                else:
                    while(s[i] == s[i-1] or s[i] == s[i+1]):
                        s[i] = self.next_char
            else:
                continue

        return ''.join(s)


