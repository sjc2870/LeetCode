#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, middle = -1;
        while(left <= right){
            middle = (left+right)/2;
            if(target == nums[middle]) {
                return middle;
            }else if(target > nums[left]) {
                right = middle;
            }else {
                left = middle;
            }
        }
        return -1;
    }
};
