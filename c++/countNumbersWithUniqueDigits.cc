#include <algorithm>

/* leetcode issue 357 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        n = std::min(n, 10);
        int ans = 10, base = 9, sum = 9;
        for(int i = 1; i < n; ++i){
            ans += sum *= base--;
        }
        return ans;
    }
};

