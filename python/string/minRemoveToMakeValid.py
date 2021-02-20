#!/usr/bin/env python3
#coding=utf-8

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        sup = []
        for idx, c in enumerate(s):
            if(c == '('):
                stack.append(idx)
            elif(c == ')'):
                if(len(stack) != 0 and s[stack[-1]] == '('):
                    t = stack.pop()
                    print(t)
                else:
                    stack.append(idx)
        print(stack)
        for i, c in enumerate(s):
            if i not in stack:
                sup.append(c)
        return ''.join(sup)
