#include <string>

using namespace std;

/* leetcode issue 1704*/
class Solution {
public:
    string st = "aeiou";
    bool judge(char c) {
        return st.find(tolower(c)) != string::npos;
    }

    bool halvesAreAlike(string s) {
        int a = 0, b = 0;
        int i = 0, j = s.size()-1;

        for(; i <=j; ++i, --j) {
            if(judge(s[i]))
                ++a;
            if(judge(s[j]))
                ++b;
        }

        return a == b;
    }
};
