#include <string>
#include <stdio.h>

//需要用kmp算法，待补充..
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        for(int i=0;i < haystack.length(); ++i){
            int j = 0;
            int saved_i = i;
            for(j = 0; j < needle.length() && haystack[i++] == needle[j]; ++j) { }
            if(j == needle.length())
                return i+1;
            i = saved_i;

        }
        return -1;
    }
};
