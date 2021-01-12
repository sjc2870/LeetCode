#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
/*找到最长公共前缀，每次比较也就是当前单词和当前公共前缀比较*/
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        for(int i = 0;i< strs.size(); ++i){
            string str = strs[i];
            if(i == 0){
                ret = strs[0];
                continue;
            }
            int minlen = min(str.length(),ret.length());
            ret = ret.substr(0,minlen);
            for(int j = 0;j < str.length() && j < ret.length();++j){
                if(str[j] != ret[j]){
                    ret = str.substr(0,j);
                    break;
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution so;
    vector<string> param = {"aa","a"};
    string ret = so.longestCommonPrefix(param);
    cout << ret << endl;
}