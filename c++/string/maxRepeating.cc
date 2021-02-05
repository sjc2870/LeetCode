#include <string>
#include <cassert>
#include <iostream>

using namespace std;
/* leetcode issue 1668 */

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        size_t ret = 0;
        string single_w = word;

        while(sequence.find(word) != string::npos) {
            ++ret;
            word += single_w;
        }
        return ret;
    }
};

int main() {
    Solution so;

    int ret;
    ret = so.maxRepeating("ababc", "ab");
    cout << ret << endl;
    assert(ret == 2);

    ret = so.maxRepeating("ababc", "ba");
    cout << ret << endl;
    assert(ret == 1);

    ret = so.maxRepeating("ababc", "ac");
    cout << ret << endl;
    assert(ret == 0);

    ret = so.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba");
    cout << ret << endl;
    assert(ret == 5);
}
