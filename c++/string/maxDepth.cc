#include <string>
#include <stdio.h>
#include <cassert>

using namespace std;

/* leetcode issue 1614 */
class Solution {
public:
    int maxDepth(string s) {
        if(s.size() == 0)
            return 0;
        int ret = 0;
        int depth = 0;

        for(char c : s) {
            if(c == '(') {
                if(++depth > ret)
                    ret = depth;
            } else if(c == ')'){
                --depth;
            }

        }

        return ret;
    }
};

int main () {
    Solution so;
    int ret = so.maxDepth("(1+(2*3)+((8)/4))+1");
    printf("ret is %d\n", ret);
    assert(ret == 3);
    ret = so.maxDepth("(1)+((2))+(((3)))");
    printf("ret is %d\n", ret);
    assert(ret == 3);
    ret = so.maxDepth("1+(2*3)/(2-1)");
    printf("ret is %d\n", ret);
    assert(ret == 1);
    ret = so.maxDepth("1");
    printf("ret is %d\n", ret);
    assert(ret == 0);
    
}
