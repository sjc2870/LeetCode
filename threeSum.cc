#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*如果在双重循环中，一个数逐渐变大，而另一个数随之减小，那么可以用双指针来优化，减小复杂度*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        int first,second,third;
        vector<vector<int>> ret;

        sort(nums.begin(),nums.end());        
        for(first = 0; first < len; ++first){
            if(first > 0 && nums[first-1] == nums[first]){
                continue;
            }
            third = len-1;
            for(second = first+1; second < len; ++second){
                if(second > first+1 && nums[second-1] == nums[second]){
                    continue;
                }
                while(second < third && nums[first] + nums[second] + nums[third] > 0){
                    --third;
                }
                if(second == third){
                    break;
                }
                if(nums[first] + nums[second] + nums[third] == 0){
                    ret.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return ret;
    }
};