#include <string>
#include <cassert>
#include <iostream>
#include <stack>

using namespace std;

/* leetcode issue 1249 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /* stack 中保留需要删除的元素下标 */
        stack<int> stk;

        for(size_t i = 0; i < s.size(); ++i) {
            if(s[i] == '(')
                stk.push(i);
            else if(s[i] == ')' && (!stk.empty() && s[stk.top()] == '('))
                stk.pop();
            else if(s[i] == ')')
                stk.push(i);
        }

        while(!stk.empty()) {
            int i = stk.top();
            stk.pop();
            s.erase(s.begin() + i);
        }

        return s;
    }
};

int main() {
    Solution so;
    string ret;

    ret = so.minRemoveToMakeValid("lee(t(c)o)de");
    cout << ret << endl;   
    assert(ret == "lee(t(c)o)de" || ret == "lee(t(c)ode)");

    ret = so.minRemoveToMakeValid("a)b(c)d");
    cout << ret << endl;
    assert(ret == "ab(c)d");

    ret = so.minRemoveToMakeValid("))((");
    cout << ret << endl;
    assert(ret == "");

    ret = so.minRemoveToMakeValid("(a(b(c)d)");
    cout << ret << endl;
    assert(ret == "a(b(c)d)" || ret == "(a(bc)d)");

    ret = so.minRemoveToMakeValid("lee(t(c)o)de)");
    cout << ret << endl;
    assert(ret == "lee(t(c)o)de");

}
