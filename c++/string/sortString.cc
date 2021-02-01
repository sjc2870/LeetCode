#include <string>
#include <vector>

using namespace std;

/* leetcode issue 1370 */
class Solution {
public:
    string sortString(string s) {
        vector<int> sup(26, 0);
        for(char c : s) {
            sup[c-'a']++;
        }

        string ret;
        while(ret.size() < s.size()) {
            for(size_t i = 0; i < sup.size(); ++i) {
                if(sup[i] != 0) {
                    ret.push_back(i+'a');
                    --sup[i];
                }
            }
            /* can't use size_t here */
            for(int i = 25; i >= 0; --i) {
                if(sup[i] != 0) {
                    ret.push_back(i+'a');
                    --sup[i];
                }
            }
        }

        return ret;
    }
};

