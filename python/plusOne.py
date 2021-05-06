#!/usr/bin/env python3
#coding=utf-8

from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = int(''.join([str(x) for x in digits]))+1
        return [int(x) for x in str(num)]
