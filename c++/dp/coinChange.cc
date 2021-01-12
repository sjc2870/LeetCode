#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount));

        for(int i = coins[0],j = 1; i <= amount; i += coins[0]) {
            dp[0][i] = j++;
        }
        dump(dp);

        for(int i = 1; i < coins.size(); ++i) {
            for(int j = 1; j <= amount; ++j) {
                int remain = j - coins[i-1];
                if(remain % coins[i] == 0) {
                    dp[i][j] = std::min(dp[i-1][j], dp[i-1][coins[i-1]] + remain%coins[i]);
                }
            }
        }
        dump(dp);
        return dp[coins.size()-1][amount];
    }

    void dump(vector<vector<int>> &p) {
        for(int i = 0; i < p.size(); ++i) {
            for( int j = 0; j < p[0].size(); ++j) {
                printf("%d ", p[i][j]);
            }
            printf("\n");
        }
        printf("---------------\n");
    }
};

int main() {
    vector<int> p {1, 2, 5};
    Solution so;
    int ret = so.coinChange(p, 11);
    printf("ret is %d\n", ret);
}
