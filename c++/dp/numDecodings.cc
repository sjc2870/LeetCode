#include <vector>

using namespace std;

/* leetcode issue 91 */

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);

        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            int cur = s[i-1]-'0';

            if (cur > 0) {
                dp[i] += dp[i-1];
            }
            if (i > 1 && s[i-2] != '0' && ((s[i-2]-'0')*10 + (s[i-1]-'0') < 27)) {
                dp[i] += dp[i-2];
            }
        }

        return dp[s.size()];
    }
};