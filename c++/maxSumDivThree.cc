#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> state(3);
        state[1] = std::numeric_limits<int>::min();
        state[2] = std::numeric_limits<int>::min();
        int a, b, c;
        for(int num : nums) {
            if(num % 3 == 0) {
                a = std::max(state[0], state[0] + num);
                b = std::max(state[1], state[1] + num);
                c = std::max(state[2], state[2] + num);
            }else if(num % 3 == 1) {
                a = std::max(state[0], state[2] + num);
                b = std::max(state[1], state[0] + num);
                c = std::max(state[2], state[1] + num);
            }else{
                a = std::max(state[0], state[1] + num);
                b = std::max(state[1], state[2] + num);
                c = std::max(state[2], state[0] + num);
            }
            state = {a, b ,c};
        }
        return state[0];
    }
};
