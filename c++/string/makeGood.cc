#include <string>
#include <cctype>
#include <cassert>
#include <iostream>

using namespace std;

/* leetcdoe issue 1544 */

class Solution {
public:
    bool isgood(char c1, char c2) {
        if(isupper(c1) && islower(c2))
            return c1 == toupper(c2);
        if(islower(c1) && isupper(c2))
            return c1 == tolower(c2);
        return false;
    }
    string makeGood(string s) {
        int len = s.size();
        string ret;
        int i = 0;
        int ret_i = -1;

        while(i < len-1) {
            if(isgood(s[i], s[i+1])) {
                i += 2;
            } else if(ret_i == -1) {
                ret.push_back(s[i]);
                ++ret_i;
                ++i;
            } else if(isgood(ret[ret_i], s[i])) {
                ret.pop_back();
                ret_i--;
                ++i;
            } else {
                ret.push_back(s[i]);
                ret_i++;
                ++i;
            }
        }

        if(i == len-1 && ret_i > -1 && isgood(ret[ret_i], s[i]))
            ret.pop_back();
        else if(i == len-1)
            ret.push_back(s[i]);
        return ret;
    }
};

int main() {
    string ret;
    Solution so;

    ret = so.makeGood("leEeetcode");
    cout << ret << endl;   
    assert(ret == "leetcode");

    ret = so.makeGood("abBAcC");
    cout << ret << "" << endl;   
    assert(ret == "");

    ret = so.makeGood("RLlr");
    cout << ret << endl;   
    assert(ret == "");

    ret = so.makeGood("hWwHhH");
    cout << ret << endl;
    assert(ret == "");
}
