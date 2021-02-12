#include <string>
#include <vector>

using namespace std;

/* leetcode issue 383 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> sup(26, 0);

        for(char c : magazine) {
            sup[c-'a']++;
        }

        for(char c: ransomNote) {
            if(sup[c-'a'] > 0) {
                sup[c-'a']--;
            } else {
                return false;
            }
        }

        return true;
    }
};
