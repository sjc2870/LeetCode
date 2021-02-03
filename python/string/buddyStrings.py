#!/usr/bin/env python3
#coding=utf-8

''' leetcode issue 859 '''

class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B): # 长度不相等必定不符合
            return False

        idx =[i for i in range(len(A))  if A[i] != B[i]]
        if len(idx) == 2 and A[idx[0]] == B[idx[1]] and A[idx[1]] == B[idx[0]]:  # 两个字符串交换两次完全相同
            return True
        if len(idx) == 0 and len(A)-len(set(A)) > 0:  # 字符串完全相同，且单个字母出现超过两次(超过两次的字母交换不影响)
            return True

        return False
