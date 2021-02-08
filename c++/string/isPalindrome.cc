#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        if(j == -1)
            return true;

        while(i <= j) {
            if(!isalnum(s[i])) {++i; continue;}
            else if(!isalnum(s[j])){ --j; continue;}
            else if(toupper(s[i]) != toupper(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
