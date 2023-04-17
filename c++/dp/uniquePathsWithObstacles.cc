#include <vector>

/*
 * leetcode issue 63
 * 和issue 62 uniquePaths思路是一样的，只不过要注意数组的初始化
 * 需要注意的是，故障点的到达方法为0，而且故障点的右边和下边的到达方法也为0
 *
*/
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid);
        int m = dp.size();
        int n = dp[0].size();


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 || j == 0) {
                    if (i != 0 && dp[i-1][j] == 0) {
                        dp[i][j] = 0;
                    } else if (j != 0 && dp[i][j-1] == 0) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};