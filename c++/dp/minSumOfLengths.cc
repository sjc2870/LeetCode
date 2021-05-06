#include <vector>
using namespace std;

/* from https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/solution/biao-zhun-de-dong-tai-gui-hua-zhu-xing-jiang-jie-b/
 */
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0, r = arr.size() - 1, ans = 2e5;
        vector<int> len(arr.size() + 1, 2e5);
        for (int l = r; l >= 0; --l) { //l,r是滑动区间的左右坐标
            sum += arr[l];
            while (sum > target) sum -= arr[r--];
            if (sum == target) {
                int curlen = r - l + 1; //子数组长度
                ans = min(ans, curlen + len[r + 1]); //子数组长度 + 后面子数组的最小长度
                len[l] = min(curlen, len[l + 1]); //更新子数组的最小长度
            }
            else len[l] = len[l + 1]; //更新子数组的最小长度
        }
        return ans == 2e5 ? -1 : ans;
    }
};