#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        std::vector<int> dp(nums.size(), 0);
        size_t i = 0;

        for(i = 0; i < dp.size(); ++i) {
            if(i == 0) {
                dp[i] = nums[i];
                continue;
            }
            if(i == 1) {
                dp[i] = std::max(nums[0], nums[1]);
                continue;
            }
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[i-1];
    }
};
