#include <stdio.h>
#include <string>
#include <vector>
#include <numeric>

#define next_c(c) ((c+1-'a')%26+'a')
#define idx(c) ((c-'a'))
/* leetcode issue 467
 * @算法思想：使用数组dp记录下以当前字符结尾的最长字串的长度，最后返回dp数组中每个元素的累加和
 * 1. 为什么要记录最长字串的长度？
 *   以输入zab为例，符合要求的字串为z a za b ab zab,所以结果为6
 *   那么zab字串其实就已经记录了b ab zab三种情况
 *   另以zabcdefg为例，包含了 g fg efg defg ... zabcdefg这几种情况
 *   所以只需要记录最长字串长度就可以了
 *
 * @难点
 *   难点其实就在于想到记录最长字串的长度，其他的方面都比较好想到
 */

using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size() == 0 || p.size() == 1){
            return p.size();
        }
        vector<int> dp(26);
        dp[idx(p[0])] = 1;
        int k = 0;
        for(int i = 0; i < p.size(); ++i) {
            if(i > 0 && next_c(p[i-1]) == p[i]){
                ++k;
            }else{
                k = 1;
            }
            dp[idx(p[i])] = std::max(dp[idx(p[i])], k);
        }
        
        return accumulate(dp.begin(),dp.end(),0);
    }
};

int main(){
    Solution so;
    int ret = so.findSubstringInWraproundString("zaba");
    printf("\nret is %d\n", ret);
}
