#!/usr/bin/env python3
from typing import List

''' leetcode issue 1262
'''


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        state = [0]*3
        state[1] = -10000
        state[2] = -10000

        m_sum = sum(nums)
        if(m_sum%3 == 0):
            return m_sum

        for num in nums:
            print(state)
            if(num % 3 == 0):
                state = [state[0] + num, state[1] + num, state[2] + num]
            elif(num % 3 == 1):
                a = max(state[0], state[2] + num)
                b = max(state[1], state[0] + num)
                c = max(state[2], state[1] + num)
                state = [a, b, c]
            else:
                a = max(state[0], state[1] + num)
                b = max(state[1], state[2] + num)
                c = max(state[2], state[0] + num)
                state = [a, b, c]

        return state[0]

so = Solution()
ret = so.maxSumDivThree([2,6,2,2,7])
print(ret)
