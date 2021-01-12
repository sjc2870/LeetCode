#include <string>
#include <iostream>
#include <vector>

using namespace std;

class PoorSolution {
public:
    /* leetcode issue 131 */
    /*@算法思想：先记录下前n个字符串所对应的结果dp[n]，那么可以根据dp[n]得到的dp[n+1]的部分是：dp[n+1]等于dp[n]中每个元素加上本字符(15-19行代码)
     *  现在考虑添加进s[n+1]出现的新情况：添加新字符后，整个字符串都会变化。如果从下标为[0,1,2,...,n]开始切分字符串,如果字串s[j:n+1]是回文，
     *  那么就把dp[j-1]对应的结果都添加字串s[j:n+1]，然后把dp[j-1]添加后的结果加入本字符串的结果(20-30行代码)。
    */
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> dp(s.size());
        string t(1,s[0]);
        dp[0].push_back(vector<string>(1, t));

        for(size_t i = 1; i < s.size(); ++i) {
            dp[i] = dp[i-1];
            auto &ret = dp[i];
            for(auto &vs:ret) {
                vs.push_back(string(1,s[i]));
            }
            for(size_t j = 0; j < i; ++j) {
                string sub = s.substr(j,i-j+1);
                bool is_rome = is_palindrome(sub);
                if(is_rome && j != 0) {
                    auto tmp = dp[j-1];
                    for(auto &vs: tmp) {
                        vs.push_back(sub);
                    }
                    for(auto &vs:tmp) {
                        ret.push_back(std::move(vs));
                    }
                } else if(is_rome && j == 0) {
                    ret.push_back(vector<string>(1, sub));
                }
            }
        }
        return  dp[s.size()-1];
    }

    void dump(vector<vector<string>> &vvs) {
        for(auto &vs:vvs) {
            for(auto &s:vs) {
                cout << s << " ";
            }
            printf("\n");
        }
        printf("==============end dump\n");
    }

    bool is_palindrome(string s){
        for(int i = 0, j = s.size()-1; i < j; ++i, --j) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};

int main() {
    PoorSolution so;
    vector<vector<string>> ret = so.partition("abb");
    printf("-----------------\n");
    for(auto &vs:ret) {
        for(auto &s:vs) {
            cout << s << " ";
        }
        printf("\n");
    }
}
