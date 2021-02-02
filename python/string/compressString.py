#!/usr/bin/env python3
#coding=utf-8

class Solution:
    def compressString(self, S: str) -> str:
        ret = str()
        if(len(S) == 0):
            return ret

        last_c = ''
        cnt = 0
        for idx, c in enumerate(S):
            if(idx == 0):
                last_c = c
                cnt += 1
            elif(c == last_c):
                cnt += 1
            else:
                ret += last_c
                ret += str(cnt)
                cnt = 1
                last_c = c
        return ret if len(ret) < len(S) else S

so = Solution()
ret = so.compressString("rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff")
print(ret)
