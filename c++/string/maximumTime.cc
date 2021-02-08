#include <string>
#include <cassert>
#include <iostream>

using namespace std;


class Solution {
public:
    string maximumTime(string time) {
        for(int i = 0; i < time.size(); ++i) {
            if(time[i] == '?') {
                if(i == 0 && time[1] !='?' && time[1] <= '3')
                    time[0] = '2';
                else if(i == 0 && time[1] == '?')
                    time[0] = '2';
                else if(i == 0)
                    time[0] = '1';
                else if(i == 1 && time[0] == '2')
                    time[1] = '3';
                else if(i == 1)
                    time[1] = '9';
                else if(i == 3)
                    time[3] = '5';
                else if(i == 4)
                    time[4] = '9';
            }
        }

        return time;
    }
};

int main () {
    Solution so;
    string ret;

    ret = so.maximumTime("?4:03");
    cout << ret << endl;
    assert(ret == "14:03");


    ret = so.maximumTime("??:3?");
    cout << ret << endl;
    assert(ret == "23:39");
}
