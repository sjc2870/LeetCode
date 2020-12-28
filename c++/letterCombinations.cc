#include <map>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return ret;
        }
        dfs(0, digits);
        return  ret;
    }

    void dfs(int len, string digits) {
        static string tmp;
        if(len == digits.size()){
            ret.push_back(tmp);
            return;
        }

        int pos = digits[len] - '0';
        for(size_t i = 0; i< strs[pos].size(); ++i) {
            tmp += strs[pos][i];
            dfs(len+1, digits);
            tmp.pop_back();
        }
    }

public:
    vector<string> strs {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
};
