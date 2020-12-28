#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len, latest;
        if(nums.size() == 0)
            return 0;
        latest = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[latest] != nums[i]){
                nums[++latest] = nums[i];
            }
        }
        len = latest+1;
        return len;
    }
};
