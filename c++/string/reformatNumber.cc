#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        number.erase(std::remove(number.begin(), number.end(), ' '), number.end());
        number.erase(std::remove(number.begin(), number.end(), '-'), number.end());

        string ret;
        int i = 0;
        int n = number.size();
        int remain = n%3;
        for(; i < n-remain-1; i+=3) {
            ret += number.substr(i,3);
            ret.push_back('-');
        }
        ret += number.substr(i, n-i);
        if(remain == 0)
            ret.pop_back();
        else if(remain == 1)
            std::swap(ret[ret.size()-2], ret[ret.size()-3]);

        return ret;
    }
};

int main () {
    string ret;
    Solution so;

    ret = so.reformatNumber("1-23-45 6");
    cout << ret << endl;

    ret = so.reformatNumber("123 4-567");
    cout << ret << endl;

    ret = so.reformatNumber("123 4-5678");
    cout << ret << endl;

    ret = so.reformatNumber("12");
    cout << ret << endl;
}
