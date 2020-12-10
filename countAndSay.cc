#include <string>
#include <string.h>

// error  to be completed
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1, i = 0;
        char latest;
        string ret, begin{"1"};
        while(n--){
            i = 0;
            ret.clear();
            cnt = 1;
            latest = begin[0];
            while(i < begin.length()){
                if(latest == begin[i]){
                    ++cnt;
                }else{
                    ret = ret + std::to_string(cnt) + begin[i];
                }
                ++i;
            }
            begin = ret;
        }
        return ret;
    }
};
