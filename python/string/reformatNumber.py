#!/usr/bin/env python3
#coding=utf-8

class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace('-','')
        number = number.replace(' ','')
        n = len(number)
        remain = n%3
        i = 0
        ret = ""
        while(i < n-remain-1):
            ret += number[i:i+3]
            i += 3
            ret += "-"

        ret += number[i:]
        if(remain == 0):
            ret = ret.rstrip('-')
        elif(remain == 1):
            ret = ret[:-3] + '-' + ret[-3] + ret[-1]
        return ret 

so = Solution()
print(so.reformatNumber("1-23-45 6"))
print(so.reformatNumber("1-23-45 67"))
