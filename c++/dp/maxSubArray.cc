#include <vector>

using namespace std;

/*
 * leetcode issue 53
 * 如果sum大于0，那么表示之前的序列和对当前元素有益，可以直接相加
 * 如果sun<=0，那么表示之前的序列和对当前元素无益，直接重置
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            if (sum > 0)
                sum += nums[i];
            else
                sum = nums[i];

            max = std::max(sum, max);
        }

        return max;
    }
};