#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

/* @算法思想：动态规划，dp[i]代表摆放前i本书所需的最小高度
 *   当我们计算dp[i]时，我们已知dp[i-1]，也就时摆放前i-1本书所需的最小高度
 *   现在我们开始摆放第i本书，假设把它摆放到单独的一层，摆放前这层的width和high都是0
 *   摆放第i本书后，我们尝试把之前摆放的书也摆放在这层，看这样会不会减小高度
 *
 * @难点：
 *   1. 状态。本提变量较多，高度，宽度，书的数量，想到把书的数量作为状态有一定难度
 *   2. 状态转移方程。不太容易想到把已经摆放的书继续摆放到同一层
 */ 
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size()+1, numeric_limits<int>::max());
        if(books.size() == 0) {
            return 0;
        }
        if(books.size() == 1) {
            return books[0][1];
        }
        dp[0] = 0;
        dp[1] = books[0][1];
        for(int i = 2; i < books.size()+1; ++i) {
            int tmp_width = 0;
            int h = 0;
            int j = i;
            while(j > 0) {
                tmp_width += books[j-1][0];
                if (tmp_width > shelf_width)
                    break;
                h = std::max(h, books[j-1][1]);
                dp[i] = std::min(dp[i], dp[j-1]+h);
                --j;
            }
        }
        return dp[books.size()];
    }
};
