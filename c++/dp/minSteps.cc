/* leetcode issue 650 */
#include <vector>
#include <algorithm>
#include <stdio.h>

/* @算法思想:动态规划，当我们计算n时，已经知道了前n-1种情况的解
 * 首先最坏的情况就是每次加一个'A'知道加到指定数量
 * 其次如果有公约数的话，可以求出在公约数的情况下的解，取最小值即可
 * case:    1 2 9 25
 * answer:  0 2 6 10
 * */
class Solution {
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        if(n == 2)
            return 2;
        std::vector<int> dp(n+1);
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3; i < n+1; ++i) {
            dp[i] = i;
            for(int j = 2; j <= i/2; ++j) {
                if(i%j == 0) {
                    int past_num = i/j-1;
                    dp[i]= std::min(dp[j]+1+past_num, dp[i]);
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("USAGE: [n]\n");
        return -1;
    }
    int n = atoi(argv[argc-1]);
    Solution so;
    int ret = so.minSteps(n);
    printf("ret is %d\n", ret);
}
