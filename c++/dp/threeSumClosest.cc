#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
/* @brief: sort + double pointer
 * @main variables: abs_ret and min_ret use to compare proximity
 *                  tmp_ret and ret use to return three num sum
 *                  */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        if(nums.size() == 3) {
            return nums[0]+nums[1]+nums[2];
        }
        int min_ret = INT_MAX;
        int ret;
        for(size_t first_idx = 0; first_idx < nums.size(); ++first_idx) {
            size_t second_idx = first_idx + 1;
            size_t third_idx = nums.size() - 1;
            while(second_idx < third_idx) {
                int tmp_ret = nums[first_idx]+nums[second_idx]+nums[third_idx]-target;
                int abs_ret = std::abs(tmp_ret);
                if(abs_ret < min_ret) {
                    ret = tmp_ret+target;
                    min_ret = abs_ret;
                    if(abs_ret == 0){
                        return target;
                    }
                }
                if(tmp_ret > 0){
                    --third_idx;
                }else if(tmp_ret < 0 ){
                    ++second_idx;
                }
            }
        }
        return ret;
    }
};
