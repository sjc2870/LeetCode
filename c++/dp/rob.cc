#include <vector>
#include <stdio.h>
#include <cassert>

using namespace std;

/* leetcode issue 198 */
/* @算法思想: 动态规划，在计算前i个最大值(dp[i])时，我们已知前i-1, i-2(dp[i-1], dp[i-2])的最大值。
 *            在路过每个房子时，有两种选择，拿现金或者不拿，可以分这两种情况讨论：
 *            如果要从nums[i]中拿现金，因为不能从相邻的房间中拿现金，那么结果是dp[i-2] + nums[i]
 *            如果不从nums[i]中拿现金，那么dp[i]就等于dp[i-1]
 *            最终dp[i]即为上述两种情况的最大值 */
/* @TODO: 空间复杂度可以进一步降低，可以看到dp[i]只与dp[i-1] dp[i-2]有关，所以只记录dp[i-1] dp[i-2]即可 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        size_t i = 2;
        for(; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
        }

        return dp[i-1];

    }
};

int main() {
    Solution so;
    int ret;
    vector<int> p{2,1,1,2};

    ret = so.rob(p);
    printf("ret is %d\n", ret);
    assert(ret == 4);

    p.assign({1,2,3,1});
    ret = so.rob(p);
    printf("ret is %d\n", ret);
    assert(ret == 4);

    p.assign({2,7,9,3,1});
    ret = so.rob(p);
    printf("ret is %d\n", ret);
    assert(ret == 12);

    p.assign({1,3,1,3,100});
    ret = so.rob(p);
    printf("ret is %d\n", ret);
    assert(ret == 103);

}
