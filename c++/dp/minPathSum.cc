#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;
/* leetcode issue 64 */
/* 算法思想和 uniquepath.cc 一样 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<vector<int>> dp (m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < n; ++j) {
                if(i == 0 && j > 0) {
                    dp[0][j] = grid[0][j] + dp[0][j-1];
                } else if (j == 0 && i > 0) {
                    dp[i][0] = grid[i][0] + dp[i-1][0];
                } else if(i >0 && j > 0) {
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution so;
    //vector<vector<int>> pa {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> pa {{1,2,3}, {4,5,6}};
    printf("%d\n", so.minPathSum(pa));
}
