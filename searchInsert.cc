#include <vector>

using namespace std;
// 排序数组查找首先要想到二分法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, middle;
      int ret = nums.size();
        while(left <= right){
            middle = ((right + left) >> 1);
            if(nums[middle] < target){
                left = middle+1;
            }else if(nums[middle] >= target){
                right = middle - 1;
                ret = middle;
            }
        }
        return ret;
    }
};
