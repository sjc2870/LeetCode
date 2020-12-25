#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
/* 算法思想：用一个数组dp来存放当前连续湍流子数组的长度
 * dp[i]的默认值为1或者2
 * 当计算dp[i]时，我们已知道dp[i-1]的值，如果当前序列可以与上一个数字组成湍流数组，则取一个较大值
 * 否则就为默认值
 */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        if(len == 1)
          return 1;
        /* vector<int> dp(len,0); */
        int *dp = new int[len];
        memset(dp,0,len*sizeof(int));
        dp[0] = 1;
        dp[1] = (arr[0]==arr[1] ? 1 : 2);
        for(int i = 2; i < len; ++i) {
            dp[i] = (arr[i-1] != arr[i] ? 2 : 1);
           if((arr[i-2] < arr[i-1] && arr[i-1] > arr[i]) || (arr[i-2] > arr[i-1] && arr[i-1] < arr[i])) {
               dp[i] = std::max(dp[i], dp[i-1]+1);
           }
        }
        int ret = 1;
        for(int i = 0; i < len; ++i) {
            if(dp[i] > ret) {
                ret = dp[i];
            }
        }
        /* return *(std::max_element(dp.begin(),dp.end())); */
        return ret;
    }
};

