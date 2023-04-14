#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
/*
 *      leetcode issue 322
 * 第一步定义状态：
 *      1. 问题的最后一步
 *          最后一步求解的问题是凑成amount金额所需的最少硬币，假设我们现在使用coins[i]来凑，那么我们需要找到凑成amount-coins[i]的最少硬币数量
 *          那么我们现在的问题是，如何找到凑成amount-coins[i]的最少硬币数量
 *          可以看到现在的问题是原问题的子问题
 *      2. 子问题
 *          那么现在的问题就是得到凑成k金额所需的最少硬币
 *          可以明显看出，现在的问题是原问题的子问题
 *          ok，我们定义一个数组dp用来记录凑成金额amount所需的最少硬币
 *  第二步定义转移方程：
 *      上面我们定义了vector<int> dp(amount+1, default_value),其中dp[amount]表示组成金额amount所需的最少金额
 *      从上面分析可以看到，当需要凑成amount金额并取第coins[i]个硬币时，需要找到组成amount-coins[i]金额时的最少硬币数量，在此基础上使用第coins[i]
 *      个硬币，那么就可以凑成amount金额。并和当前组成金额amount所需的最少硬币数量做笔记取最小值
 *      翻译为代码也就是dp[amount] = std::min(dp[amount], 1 + dp[amount - coins[i]]);
 *  第三步定义循环方式：
 *      从上面分析我们看出，要想得到dp[amount]，那么假设当前取coins[i]，我们需要知道dp[amount - coins[i]]。依次递归，我们需要知道dp[0~amount]，也
 *      就是需要计算dp[0~amount]，为了计算dp[0~amount],我们需要进行一次循环。这是外层循环，而内层循环则是我们依次取每个硬币所得到的结果，也就是对
 *      硬币进行循环
 *
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        /* 存放 */
        vector<int> dp(amount+1, amount);

        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = std::min(dp[i], 1 + dp[i-coins[j]]);
            }
        }

        return dp[amount] == amount ? -1 : dp[amount];
    }
};

int main() {
    vector<int> p {1, 2, 5};
    Solution so;
    int ret = so.coinChange(p, 11);
    printf("ret is %d\n", ret);
}
