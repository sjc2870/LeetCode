#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> a;
        for(int i : nums) {
            if(a.find(i) == a.end()) {
                a[i] = true;
            }else
                return true;
        }
        return false;
    }
};
