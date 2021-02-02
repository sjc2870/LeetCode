#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        string ret;
        if(S.size() == 0)
            return ret;
        size_t cnt = 0;
        char last_c;

        for(size_t i = 0; i < S.size(); ++i) {
            if(i == 0) {
                ++cnt;
                last_c = S[i];
            } else if(last_c == S[i]) {
                ++cnt;
            } else {
                ret.push_back(last_c);
                ret += std::to_string(cnt);
                cnt = 1;
                last_c = S[i];
            }
        }
        ret.push_back(last_c);
        ret += std::to_string(cnt);

        if(ret.size() < S.size())
            return ret;
        else
            return S;
    }
};
