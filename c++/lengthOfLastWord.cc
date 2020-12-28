#include <string>
#include <ctype.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        if(s.length() == 0)
            return 0;
        int i;
        for(i = s.length()-1; i>=0; --i) {
            if(!isblank(s[i]))
                break;
        }
        if(i == 0 && isblank(s[i]))
            return 0;
        for(int j = i; j>=0; --j) {
            if(isblank(s[j]))
                break;
            ++ret;
        }
        return ret;
    }
};

