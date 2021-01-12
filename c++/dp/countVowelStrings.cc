#include <stdio.h>
#include <string.h>

using namespace std;
/* @算法思想：动态规划和插入法的思想，当我们计算长度为n的情况时，我们已知道长度为n-1的情况
 * 现在开始把长度+1，当插入a时，n-1的所有情况都可以插入
 *                   当插入e时，n-1的所有情况中，只有以e及之后的字母开头的可以插入
 *                   当插入i时，n-1的所有情况中，只有以i及之后的字母开头的可以插入
 *                   ......o.,........................ o.........................
 * 具体看来 当计算n=3时的情况 
 * n=2时情况如图
 * aa ae ai ao au   ...line 1
 *    ee ei eo eu   ...line 2
 *       ii io iu   ...line 3
 *          oo ou   ...line 4
 *             uu   ...line 5
 * 当我们插入a时，所有行都可以插入
 * 当我们插入e时，只有插入2-5行才可以保证有序
 * 当我们插入i时，只有插入3-5行才可以保证有序
 * ...
 * 最终用一个dp[i]数组存放n=i时，分别以a e i o u开头的字符串数目
 * 那么其实dp[i][0]=dp[i-1][0-4]之和
 *     dp[i][1]=dp[i-1][1-4]之和
 *     dp[i][2]=dp[i-1][2-4]之和
 * 
 * @TODO:可改进的地方是，我们虽然分配了长度为n的二维数组，但我们计算情况为n时并不关心0-n-2的情况，
 * 我们只关心n-1的情况，可以把二维数组的长度缩小为dp[2][5]。每次计算完n时，更新n-1，继续计算下一个n+1
 */ 
class Solution {
public:
    int countVowelStrings(int n) {
        if(n == 1) 
            return 5;
        int **dp = new int*[n];
        for(int i = 0; i < n; ++i){
            dp[i] = new int[5]();
        }
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
        dp[0][3] = 1;
        dp[0][4] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 5; ++j) {
                for(int k = j; k < 5; ++k){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4];
    }
};

int main() {
    Solution so;
    int ret = so.countVowelStrings(33);
    //int ret = so.countVowelStrings(2);
    printf("ret is %d\n", ret);
}
