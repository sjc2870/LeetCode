#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        size_t first, second, third;
        
        std::sort(nums.begin(), nums.end());
        for(first = 0; first < nums.size(); ++first){
            int target = 0 - nums[first];
            second = first + 1;
            third = nums.size() -1;
            if(first > 0 && nums[first -1] == nums[first]){
                continue;
            }
            while(second < third){
                int add_ret;
                if((add_ret = nums[second] + nums[third]) == target){
                    ret.push_back({nums[first], nums[second], nums[third]});
                    --third;
                    ++second;
                    while(second < third && nums[second] == nums[second-1]) ++second;
                    while(second < third && nums[third] == nums[third+1]) --third;

                }else if (add_ret > target){
                    --third;
                }else{
                    ++second;
                }
            }
            
        }
        return ret;
    }
};
