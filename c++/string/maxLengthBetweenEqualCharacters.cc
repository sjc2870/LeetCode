#include <stdio.h>
#include <string>
#include <cassert>
#include <vector>

using namespace std;

/* leetcode issue 1624 */
/* 有关重复字符都可以用辅助数组来记录 */
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        /* 用来记录字符第一次出现的位置 */
        vector<int> sup(26, -1);
        int ret = -1;

        for(int i = 0; i < s.size(); ++i) {
            if(sup[s[i] - 'a'] != -1) {
                ret = std::max(i-sup[s[i]-'a']-1, ret);
            } else {
                sup[s[i] - 'a'] = i;
            }
        }
        return ret;
    }
};

int main() {
    Solution so;

    int ret;
    ret = so.maxLengthBetweenEqualCharacters("aa");
    printf("ret is %d\n", ret);
    assert(ret == 0);

    ret = so.maxLengthBetweenEqualCharacters("abca");
    printf("ret is %d\n", ret);
    assert(ret == 2);

    ret = so.maxLengthBetweenEqualCharacters("cbzxy");
    printf("ret is %d\n", ret);
    assert(ret == -1);

    ret = so.maxLengthBetweenEqualCharacters("cabbac");
    printf("ret is %d\n", ret);
    assert(ret == 4);
}
