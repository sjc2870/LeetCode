#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(0,digits.size());
        int carry = 0;
        int i = digits.size()-1;

        ret.assign(digits.cbegin(), digits.cend());
        for(; i >= 0; --i) {
            if(i == digits.size()-1) {
                ret[i] += 1;
                carry = ret[i]/10;
                ret[i] %= 10;
            } else {
                if(carry == 0) {
                    break;
                }
                ret[i] += carry;
                carry = ret[i]/10;
                ret[i] %= 10;
            }
        }
        if(carry == 1) {
            ret.insert(ret.begin(), 1);
        }
        return ret;
    }
};

int main() {
    Solution so;
    vector<int> p;
    p.assign({1,2,3});
    vector<int> ret = so.plusOne(p);
    for(int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;
}
