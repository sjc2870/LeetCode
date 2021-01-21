#include<vector>

using namespace std;

/* leetcode issue 674 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur = 1;
        int ret = 0;

        if(nums.size() == 0)
            return 0;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i-1]) {
                ++cur;
            } else {
                ret = std::max(ret, cur);
                cur = 1;
            }
        }
        ret = std::max(ret, cur);
        return ret;
    }
};
