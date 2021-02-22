#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

/* leetcode issue 1143 */
/* @算法思想：  dp[i][j]代表text1[:i]和text[:j]的最大公共子序列
 *              那么计算dp[i][j]时，我们已知dp[i-1][j-1] dp[i-1][j] dp[i][j-1]
 *              如果text[i] == text[j]，那么dp[i][j]=dp[i-1][j-1]+1，意思就是取这两个字符串的前一位置的最大共子序列+1
 *              如输入为adc和abc，计算dp[3][3]时，此时c和c相同，那么取ad和ac的最大公共子序列+1
 *              如果text[i] != text[j],那么dp[i][j] = std::max(dp[i][j-1], dp[i-1][j])
 *              如输入为abcd和abce，计算dp[4][4]时，此时d!=e,则取abc和abce的最大公共子序列和abcd和abc的最大公共子序列的最大值*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size();
        int columns = text2.size();

        vector<vector<int>> dp(rows+1, vector<int>(columns+1,0));
        int i = 0, j = 0;
        for(; i < rows+1; ++i) {
            for(j = 0; j < columns+1; ++j) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                    if(text1[i-1] == text2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
        }
        return dp[i-1][j-1];
    }
};

int main() {
    Solution so;
    int ret;

    ret = so.longestCommonSubsequence("abcde", "ace");
    cout << ret << endl;
    assert(ret == 3);

    ret = so.longestCommonSubsequence("abc", "abc");
    cout << ret << endl;
    assert(ret == 3);

    ret = so.longestCommonSubsequence("abc", "def");
    cout << ret << endl;
    assert(ret == 0);
}
