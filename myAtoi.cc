#include <string>
#include <iostream>
#include <ctype.h>
#include <limits.h>

using namespace std;
// state
//      0：未处理  1：有符号整数  2：整数   3：结束

class Solution {
public:
    int myAtoi(string str) {
       int i = 0;
       int len = str.length();
       int ret = 0;
       int state = 0;
       int sign = 1;

       for(i = 0;i < len; ++i){
           if(str[i] == ' ' && state==0){
               continue;
           }
           if(str[i] == '-' && state==0){
               sign = -1;
               state=1;
               continue;
           }else if(str[i] == '+' && state ==0){
               state=1;
               continue;
           }else if(!isdigit(str[i])&& state!=0){
               return ret;
           }
            if(!isdigit(str[i])){
                return ret;
            }
            /*越界处理*/
            if(ret >0 && (ret > INT_MAX/10 || ret*10 > INT_MAX-(str[i]-'0'))){
                return INT_MAX;
            }else if(ret < INT_MIN/10 || ret*10 < INT_MIN+(str[i]-'0')){
                return INT_MIN;
            }
            if(ret >= 0){
                ret = ret *10 + (str[i] - '0');
                state = 1;
            }else {
                ret = ret *10 - (str[i] - '0');
                state = 1;
            }
            if(ret !=0 ){
            ret *=sign;
            sign = 1;
            }
       }
       return ret; 
    }
};
int main(int argc,char **argv){
    Solution so;
    int ret = so.myAtoi("-000000000000001");
    cout << "ret is " << ret << endl;
}