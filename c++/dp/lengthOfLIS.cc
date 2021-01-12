#include <vector>
#include <stdio.h>
#include <limits>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int def = std::numeric_limits<int>::max();
        int dp[len+1] = {0};
        for(auto &c:dp){
            c = def;
        }
        dp[1] = nums[0];
        dp[0] = std::numeric_limits<int>::min();
        for(int i = 1; i < len; i++) {
            for(int j = 1; j < i+1; j++) {
                if(nums[j] > dp[i-1] && nums[j] < dp[i]) {
                    dp[i] = nums[j];
                }
            }
        }
        return dp[len-1];
    }
};

int main(){
    Solution so;
    //vector<int> par = {10,9,2,5,3,7,101,18,19};
    vector<int> par = {1,3,6,7,9,4,10,5,6};
    int ret = so.lengthOfLIS(par);
    printf("ret is %d\n", ret);
}
