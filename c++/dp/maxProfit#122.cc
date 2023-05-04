#include <vector>

using namespace std;

/* leetcode issue 122 */
/* 
 * 每过一天，自己有两种状态，持有股票或者没有持有股票
 * 用二维数组来表示自己每天的最大利润，第一维代表每天，第二维代表持有股票或者没有持有股票
 * 第0天没有持有股票的最大利润为0，持有股票的最大利润为-prices[0]
 * 第i天不持有股票的最大利润为 前一天不持有股票的最大利润和前一天持有股票但是今天卖掉的最大利润的最大值
 * 第i天持有股票的最大利润为   前一天持有股票的最大利润和前一天不持有股票但是今天买入的最大利润的最大值 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return std::max(dp[n-1][0], dp[n-1][1]);
    }
};