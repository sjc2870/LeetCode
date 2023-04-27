#include <vector>


/*leetcode issue 120 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        
        vector<vector<int>> dp(triangle);

        dp[0][0] = triangle[0][0];
        int n = triangle.size();
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else if (j > 0) {
                    dp[i][j] = std::min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};