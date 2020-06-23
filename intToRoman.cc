#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace  std;
#if 1
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> um0 = {
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"}
        };
        unordered_map<int,string> um1 = {
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"}
        };
        unordered_map<int,string> um2 = {
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"}
        };
        unordered_map<int,string> um3 = {{1000,"M"}};
        unordered_map<int,unordered_map<int,string>> um = {
            {1,um0},
            {10,um2},
            {100,um1},
            {1000,um3}
            };
        string ret;
        int n = 1;
        while(num/n){
            n *= 10;
        }
        n /= 10;
        string s = to_string(num);
        int len = s.length();
        int j;
        for(int i = 0; i < len; ++i){
            j = s[i]-'0';
            auto p = um[n];
            while (j > 0){
                if(j <= 3){
                    ret += p[n];
                    j -= 1;
                }else if(j == 4 || j == 5){
                        ret += p[j*n];
                        j -= j;
                }else if(j <= 8){
                    j -= 5;
                    ret += p[5*n];
                }else if(j == 9){
                    j -= 9;
                    ret += p[9*n];
                }
            }
            n /= 10;
        }
        return ret;
    }
};
#endif

int main(){
    Solution so;
    string ret  = so.intToRoman(1994);
    cout << "ret is " << ret << endl;
}