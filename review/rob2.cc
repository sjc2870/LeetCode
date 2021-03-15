#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return std::max(nums[0], nums[1]);
        return std::max(rob_core(nums, 0, nums.size()-2), rob_core(nums, 1, nums.size()-1));
    }

    int rob_core(std::vector<int>& nums, int beg, int end) {
        std::vector<int> dp(end-beg+1, 0);
        size_t i = 0;
        for(; i < end-beg+1; ++i) {
            if(i == 0) {
                dp[i] = nums[beg];
                continue;
            }
            if(i == 1) {
                dp[i] = std::max(nums[beg], nums[beg+1]);
                continue;
            }
            dp[i] = std::max(dp[i-1], dp[i-2]+nums[beg+i]);
        }
        return dp[i-1];
    }
};