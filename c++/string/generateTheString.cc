#include <string>
#include <iostream>

using namespace std;

/* leetcode issue 1374 */
class Solution {
public:
    string generateTheString(int n) {
        string s = "abcdefghijklmnopqrstuvwxyz";
        string ret("a");

        while(n >= 26) {
            ret += "aa";
            n-= 2;
        }
        ret += s.substr(1, n-1);
        return ret;
    }
};

