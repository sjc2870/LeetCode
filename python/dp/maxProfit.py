''' leetcode issue 714
    动态规划，当天的收益只与前一天有关
    每天的状态有两种，手里有股票的收益或者没有股票的收益
    状态1：手里有股票
        可能是前一天有股票，当天没有发生交易，这种情况要继承的上一天的收益
        也可能是前一天没有股票，当天发生了交易，这种情况的收益等于用上一天的没有股票的收益减去当天的股票价格
        当天有股票的收益等于两者收益的最大值
    状态2：手里没有股票
        可能是前一天没有股票，当天没有发生交易，这种情况要继承的上一天的收益
        也可能是前一天手里有股票，当天将它卖出，这种情况的收益等于要加上当天的股价减去fee
        当天手里没有股票的收益等于两者的最大值
'''
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # on 代表手里有股票的收益
        # off 代表手里没有股票的收益
        on = -prices[0]
        off = 0
        length = len(prices)
        for i in range(1,length):
            on, off = max(on, off-prices[i]), max(off,prices[i]-fee+on)
        return off
