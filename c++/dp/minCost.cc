#include <vector>
#include <algorithm>
#include <stdio.h>


using namespace std;

/* leetcode issue 256 */
class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        vector<int> dp(3, 0);
        if(costs.size() == 0)
        return 0;
        int a = 0, b = 0, c = 0;
        dp[0] = costs[0][0];
        dp[1] = costs[0][1];
        dp[2] = costs[0][2];
        for(size_t i = 1; i < costs.size(); ++i) {
            a = std::min(dp[1], dp[2]) + costs[i][0];
            b = std::min(dp[0], dp[2]) + costs[i][1];
            c = std::min(dp[0], dp[1]) + costs[i][2];

            dp[0] = a;
            dp[1] = b;
            dp[2] = c;

        }
        return *std::min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution so;
    vector<vector<int>> p {{14,2,11},{11,14,5},{14,3,10}};
    vector<vector<int>> p2 {{1,2,3},{1,4,6}};

    int ret = so.minCost(p);
    printf("ret: %d\n", ret);
    ret = so.minCost(p2);
    printf("ret: %d\n", ret);
}
