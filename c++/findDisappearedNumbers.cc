#include <vector>
#include <iostream>

using namespace std;

/*leetcode issue 448 */
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();

        for(int num : nums) {
            int x = (num-1) % n;
            nums[x] += n;
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] <= n) {
                ret.push_back(i+1);

            }
        }

        return ret;
    }
};

int main() {
    Solution so;

    vector<int> ret;

    vector<int> p{4,3,2,7,8,2,3,1};
    ret = so.findDisappearedNumbers(p);
    for(int i : ret) {
        cout << i << endl;
    }
}
