#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();
        int prev = 0;
        while(i < n) {
            while(!isblank(s[i]) && i < n)
                ++i;
            cout << "before:" << s << " ";
            std::reverse(s.begin()+prev, s.begin()+i);
            cout << "after:" << s << endl;
            ++i;
            prev = i;
        }
        return s;
    }
};

int main() {
    string ret;
    Solution so;

    ret = so.reverseWords("123 456 789");
    cout << "ret:" << ret << endl;

}
