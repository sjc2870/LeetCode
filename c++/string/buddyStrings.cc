#include <string>
#include <iostream>

using namespace std;
/* leetcode issue 859 */
/* @算法思想： 找到两个不相等的字符，进行比较即可 */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A.size() == 0 || B.size() == 0)
            return false;

        size_t i = 0;
        while(i < A.size() && A[i] == B[i]) {
            ++i;
        }
        if(i == A.size()) {
            /* 查找字符串中是否有重复字符，不需用双循环，而是采用一个数组来记录即可 */
            char sup[26] = {0};
            for(char c : A) 
                sup[c-'a']++;
            for(int c : sup)
                if(c > 1) return true;
            return false;
        }
        size_t j = i+1;
        while(j < A.size() && A[j] == B[j])
            ++j;

        size_t k = j+1;
        while(k < A.size() && A[k] == B[k])
            ++k;
        if(k != A.size())
            return false;

        cout << A[i] << A[j] << " " << B[i] << B[j] << endl;
        if(j == A.size())
            return false;
        else if(A[i] == B[j] && A[j] == B[i])
            return true;
        return false;

    }
};

int main() {
    Solution so;
    cout << so.buddyStrings("abab", "abab") << endl;
    cout << so.buddyStrings("ab", "ba") << endl;
    cout << so.buddyStrings("ab", "ab") << endl;
    cout << so.buddyStrings("aa", "aa") << endl;
    cout << so.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    cout << so.buddyStrings("abcd", "badc") << endl;
}
