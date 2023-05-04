#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

/* leetcode issue 139 */

/*
 * 解题思路：在查看s[0~i]是否能被拼接成时，假设已经知道s[0~i]的子串能否被拼接，再加上剩下的子串能否被拼接，即可
 * 知道这个字符串s[0~i]能否被拼接。
 * 
 * base case: 空串肯定能被拼接
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set;
        vector<bool> dp(s.size() + 1);

        dp[0] = true;
        for (auto &word:wordDict) {
            word_set.insert(word);
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                /* 
                 * dp[j]表示子串s[0~j-1]能否被拼接
                 * word_set.find 表示子串[j,i-j]能否被拼接
                 */
                if (dp[j] && word_set.find(s.substr(j, i-j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[dp.size()-1];
    }
};