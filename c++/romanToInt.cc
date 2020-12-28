#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        unordered_map<char,int> um = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
            {'D',500},{'M',1000}
        };
        int ret = 0;
        for(int i = 0;i < len; ++i){
            if(s[i] == 'I'){
                if(i+1 < len && (s[i+1]=='V'||s[i+1]=='X')){
                    ret += (um[s[i+1]] -1);
                    i++;
                }else{
                    ret += 1;
                }
            }else if(s[i] == 'X'){
                if(i+1 < len && (s[i+1] == 'L' || s[i+1] == 'C')){
                    ret += (um[s[i+1]] - 10);
                    i++;
                }else{
                    ret += 10;
                }
            }else if(s[i] == 'C'){
                if(i+1 < len && (s[i+1] == 'D') || s[i+1] == 'M'){
                    ret += (um[s[i+1]] - 100);
                    i++;
                }else{
                    ret += 100;
                }
            }else{
                ret += um[s[i]];
            }
        }
        return ret;
    }
    
};


int main(){
    Solution so;
    int ret = so.romanToInt("MCMXCIV");
    cout << "ret is " << ret << endl;
}