#include <vector>
#include <algorithm>

using namespace  std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;

        if(nums.size() < 4){
            return ret;
        }
        auto length = nums.size();
        std::sort(nums.begin(), nums.end());
        for(size_t i = 0; i < nums.size()-3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if((nums[i] + nums[i+1] + nums[i+2] + nums[i+3]) > target) {
                break;
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
              continue;
          }
            for(size_t j = i+1; j < nums.size()-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                size_t left = j+1;
                size_t right = nums.size() -1;
                while(left < right) {
                    int cmp_target = nums[i]+nums[j]+nums[left]+nums[right];
                    if(cmp_target> target) {
                        --right;
                    }else if(cmp_target < target) {
                        ++left;
                    }else{
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) {
                            ++left;
                        }
                        ++left;
                        while(left < right && nums[right] == nums[right-1]) {
                            --right;
                        }
                        --right;
                    }
                }
            }
        }
        return ret;
    }
};

