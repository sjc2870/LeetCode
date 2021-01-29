#!/usr/bin/env python3
#coding=utf-8
class Solution:
    """
    @param costs: n x 3 cost matrix
    @return: An integer, the minimum cost to paint all houses
    """
    def minCost(self, costs):
        if(len(costs) == 0):
            return 0

        dp = []
        dp.append(costs[0][0])
        dp.append(costs[0][1])
        dp.append(costs[0][2])

        for i in range(1, len(costs)):
            a = min(dp[1], dp[2]) + costs[i][0]
            b = min(dp[0], dp[2]) + costs[i][1]
            c = min(dp[0], dp[1]) + costs[i][2]

            dp[0], dp[1], dp[2] = a, b, c

        return min(dp)

