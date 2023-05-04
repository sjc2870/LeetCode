#include<vector>

using namespace std;

/*leetcode issue 121 
 * 假设在第i天卖出，那么该天能获得的最大利润就是该天的价格减去之前的最小价格
 * 然后再和之前的最大利润比较，取最大值
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;

        for (auto& price: prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
    }
};