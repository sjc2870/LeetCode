#include <string>
#include <cctype>

using namespace std;

/* leetcode issue 434 */

class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0)
            return 0;
        int ret = 0;
        bool in_word = false;

        for(char c : s) {
            if(isblank(c) && in_word) {
                in_word = false;
            } else if (!in_word && !isblank(c)) {
                in_word = true;
                ++ret;
            }
        }
        return ret;
    }
};
