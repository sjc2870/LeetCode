#include <cctype>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(!S.size())
            return "";
        if(S.size() == 1)
            return S;

        for(size_t i = 0, j = S.size()-1; i <= j;) {
            if(!isalpha(S[i])) {
                ++i;
                continue;
            }
            if(!isalpha(S[j])) {
                --j;
                continue;
            }
            std::swap(S[i], S[j]);
            ++i;
            --j;
        }
        return S;
    }
};

int main () {
    Solution so;
    string ret = so.reverseOnlyLetters("ab-cd");
    assert(ret == "dc-ba");
    ret = so.reverseOnlyLetters("a-bC-dEf-ghIj");
    assert(ret== "j-Ih-gfE-dCba");
    ret = so.reverseOnlyLetters("Test1ng-Leet=code-Q!");
    assert(ret == "Qedo1ct-eeLg=ntse-T!");
}
