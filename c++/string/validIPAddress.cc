#include <string>
#include <iostream>
#include <cctype>
#include <cassert>
#include <regex>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        regex ipv4("([0-9]|[1-9][0-9]|2[0-4])");
    }
    /*
    string validIPAddress(string IP) {
        if(IP.size() == 0)
            return "Neither";
        int period_num = std::count(IP.begin(), IP.end(), '.');
        int colon_num = std::count(IP.begin(), IP.end(), ':');
        string sub;
        size_t cur = 0;

        if(IP[IP.size()-1] == '.' || IP[IP.size()-1] == ':')
                return "Neither";
        if(period_num == 3) {
            while(cur < IP.size()) {
                sub.clear();
                //if(IP[cur] == '0')
                  //  return "Neither";
                while(IP[cur] != '.' && cur < IP.size()) {
                    if(isdigit(IP[cur])) {
                        sub.push_back(IP[cur]);
                        ++cur;
                    } else {
                        return "Neither";
                    }
                }
                ++cur;
                int num = -1;
                if(sub.size() > 0 && sub.size() < 4) {
                    num = std::stoi(sub);
                }
                if(num < 0 || num > 255 || (sub.size() > 1 && sub[0] == '0'))
                    return "Neither";
            }
            return "IPv4";
        } else if(colon_num == 7) {
            while(cur < IP.size()) {
                sub.clear();
                while(IP[cur] != ':' && cur < IP.size()) {
                    if(isxdigit(IP[cur])) {
                        ++cur;
                        sub.push_back(IP[cur]);
                    } else {
                        return "Neither";
                    }
                }
                ++cur;
                if(sub.size() == 0 || sub.size() > 4) {
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }*/
};

int main() {
    Solution so;
    string ret;

    ret = so.validIPAddress("172.16.254.1");
    cout << ret << endl;
    assert(ret == "IPv4");

    ret = so.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
    cout << ret << endl;
    assert(ret == "IPv6");

    ret = so.validIPAddress("12..33.4");
    cout << ret << endl;
    assert(ret == "Neither");

    ret = so.validIPAddress("192.0.0.1");
    cout << ret << endl;
    assert(ret == "IPv4");

    ret = so.validIPAddress("00.0.0.0");
    cout << ret << endl;
    assert(ret == "Neither");
}
