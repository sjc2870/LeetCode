# 比较精简的解法
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s.rstrip()
        if(len(s) == 1):
            return 1
        s_new = s.split(" ")
        return len(s_new[-1])

# 下面这种方法可能会更快一些
# class Solution(object):
#     def lengthOfLastWord(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         if s.isspace():
#             return 0
#         length = len(s)
#         j = 0
#         ret = 0
#         for i in range(length-1,0,-1):
#             if s[i] == ' ':
#                 pass
#             else:
#                 j = i
#                 break
#         for i in range(j,0,-1):
#             if(s[i] == ' '):
#                 break
#             else:
#                 ret++
#         return ret

