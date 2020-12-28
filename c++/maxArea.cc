#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,r = height.size() -1;
        int ans = 0;
        while( l < r){
            int area = min(height[l],height[r]) * (r-1);
            ans = max(area,ans);
            if(height[l] < height[r]){
                ++l;
            }else{
                ++r;
            }
        }
        return ans;
    }
};