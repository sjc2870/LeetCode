''' leetcode 467 issue 
    thinking in c++ version
''' 
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        if(len(p) < 2):
            return len(p)
        from collections import defaultdict
        dp = defaultdict(int)
        dp[p[0]],cur_max = 1, 1
        for i in range(1,len(p)):
            if((ord(p[i]) - ord(p[idx-1])) % 26 ==1):
                cur_max += 1
            else:
                cur_max = 1
            dp[p[i]] = max(dp[p[i]], cur_max)
        return sum(dp.values)
