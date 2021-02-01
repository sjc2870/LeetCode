#include <string>
#include <iostream>

using namespace std;

/* leetcode issue 459 */
/* @算法思想: 证明充要条件：对于一个字符串 SS 由多个重复的子字符串 S'
 * 组成，S肯定是S'的n数倍；因此如果将 S 与 S 首尾拼接得到拼接结果SS
 * 再将SS的首位字符去掉得到SS'，如果S是符和题目条件的，那么在SS'中自然有重复子串来再次构造S
 * 如果不符合题目条件，那么就无法再SS'中找到S
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ds = (s+s).substr(1, 2*s.size()-2);
        return ds.find(s) != string::npos;
    }
};

