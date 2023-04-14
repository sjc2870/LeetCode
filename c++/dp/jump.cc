#include <vector>
#include <limits.h>

using namespace std;

/*
 * leetcode issue 45
 * dp解法
 * 要求得我们要跳到nums[n]处的最小跳数，假设我们从nums[k]起跳，那么所需的最小跳数需要符合几个条件：
 *      1. 从nums[k]可以跳到nums[n]，也就是nums[k] + k >= n
 *      2. 得到nums[k]的最小跳数
 * 第一个简单，难点在于第二个问题
 * 可以看出，第二个问题是原问题的子问题，所以我们使用动态规划，使用dp数组来记录跳到nums[n]时所需的最少跳数
 *
 * 循环方式：
 *      要求解dp[n]，那么就要求解dp[0~n-1]，这是一层循环
 *      要求解dp[i]，那么就要根据num[0~i]来求解，这是第二层循环
 *
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j + nums[j] >= i) {
                    dp[i] = std::min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[nums.size() - 1];
    }
};