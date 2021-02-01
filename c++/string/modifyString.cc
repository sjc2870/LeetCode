#include <string>
#include <ctime>

using namespace std;

/* leetcode issue 1576 */
class Solution {
public:
    char next_char() {
        return rand()%26 + 'a';
    }

    string modifyString(string s) {
        std::srand(time(nullptr));

        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == '?' && i == 0) {
                while((s[i] = next_char()) == s[i+1]) {}
            } else if (s[i] == '?' && i != s.size() -1) {
                while((s[i] = next_char()) == s[i+1] || (s[i] == s[i-1])) {}
            } else if(s[i] == '?' && i == s.size()-1 ) {
                while((s[i] = next_char()) == s[i-1]) {}
            }
        }

        return s;
    }
};

