#include <vector>

using namespace std;

/* leetcode issue 55 */
/*第一步定义状态：
 *   1. 问题的最后一步：
 *   最后一步求解的问题是能否到达坐标n,假设我们可以从坐标k到达，那么有两个前提条件：一是可以到达坐标k，二是可以从坐标k跳到坐标n。第二个比较好算，也就是k+nums[k] >= n，比较难算的是第一个能否到达坐标k
 *   2. 子问题
 *   现在我们要求的就是能否到达坐标k
 *   原问题是能否到达坐标n
 *   可以明显看出，这是原问题的子问题，我们已经缩小了问题的规模
 *   ok，状态分析完毕，用一个数组dp来记录能否到达坐标x
 * 第二步定义转移方程：
 *   上面分析中已经说过，要想到达坐标n，那么必须满足两个条件，一是可以到达坐标k，二是可以从坐标k到达坐标n
 *   写成代码也就是if(dp[k] && k + nums[k] >= n) dp[n] = true;
 *   我们计算dp[n]时，可以从n-1, n-2, n-3,...,0来计算，看能否从dp{n-1,n-2...,0}来到达n,这样也符和我们的思路

 * 第三步定义初始值和边界情况：
 *   初始情况我们一定是可以到达坐标0的，也就是dp[0] = true

 * 第四步定义循环方式：
 *   第二步中分析，第二个循环是倒叙的，当然也可以写成正序
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >=0; --j) {
                if(dp[j] && j + nums[j] >= i){
                    dp[i] = true;
                    break;
                }
            }
        }
    return dp[n-1];
    }
};
