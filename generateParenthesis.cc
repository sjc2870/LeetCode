#include <vector>
#include <algorithm>
#include <string>

using namespace  std;

class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        if(n <= 0) {
            return ret;
        }
        generateCore("", n, n);
        return ret;
    }

    void generateCore(string tmp_ret, int left, int right) {
        if(left == right && right == 0) {
            ret.push_back(tmp_ret);
            return;
        }
        if(left == 0) {
            generateCore(tmp_ret+")", left, right-1);
        }else if(left < right){
            if(left > 0) {
                generateCore(tmp_ret+"(", left-1, right);
            }
            generateCore(tmp_ret+")", left, right-1);
        }else if(left == right) {
            generateCore(tmp_ret+"(", left-1, right);
        }
    }
};

