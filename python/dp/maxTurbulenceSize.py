class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        length = len(arr)
        if length == 1:
            return 1
        dp = []
        dp.append(1)
        dp.append(1 if arr[0] == arr[1] else 2)
        for i in range(2,length):
            dp.append(1 if arr[i]==arr[i-1] else 2)
            if((arr[i-2] > arr[i-1] and arr[i-1] < arr[i]) or (arr[i-2] < arr[i-1] and arr[i-1] > arr[i])):
                dp[i] = max(dp[i], dp[i-1]+1)

        return max(dp)
