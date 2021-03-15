#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int respace(std::vector<std::string>& dictionary, std::string sentence) {
        int n = sentence.size();
        std::vector<int> dp(n+1,0);
        for(int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for(int j = 0; j < i; ++j) {
                if(std::find(dictionary.begin(), dictionary.end(), sentence.substr(j,i-j+1)) != dictionary.end()) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};
