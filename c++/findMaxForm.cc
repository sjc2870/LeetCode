#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
class Solution {
public:
    int dp[605][105][105];
    int findMaxForm(vector<string>& strs, int m, int n) {
          int len = strs.size();

        for(int i = 1; i <= len; ++i) {
            int cnt[2] = {0};
            cnt_zero_one(cnt, strs[i-1]);
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(j >= cnt[0] && k >= cnt[1]){
                        dp[i][j][k] = std::max(dp[i-1][j][k], dp[i-1][j-cnt[0]][k-cnt[1]]+1);
                    }
                }
            }
        }
        return dp[len][m][n];
    }
    void cnt_zero_one(int *cnt, string s) {
        for(auto c:s){
            if(c == '0') {
                ++cnt[0];
            }else{
                ++cnt[1];
            }
        }
    }
};

