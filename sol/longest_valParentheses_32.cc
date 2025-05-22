/**
 * See LC 32 for PS
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() <= 1) return 0;
        // 1: DP Solution
        // vector<int> max_at(s.length(), 0);
        // int ret = 0;
        // for (int i = 1; i < max_at.size(); i++) {
        //     if (s[i] == ')') {
        //         if (s[i-1] == '(') {
        //             max_at[i] = (i - 2) >= 0? max_at[i-2] + 2:2;
        //         } else {
        //             int prev_long = i - max_at[i-1] - 1;
        //             if (prev_long >= 0 and s[prev_long] == '('){
        //                 max_at[i] = max_at[i-1] + 2 + ((prev_long - 1)>=0 ? max_at[prev_long-1]:0);
        //             }
        //         }
        //         ret = max(ret, max_at[i]);
        //     }
        // }
        // return ret;

        // 2: Stack solution
        int max_len = 0;
        int cur_len = 0;
        stack<int> open_indx;
        open_indx.push(-1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open_indx.push(i);
            } else {
                open_indx.pop();
                if (open_indx.empty()) {
                    open_indx.push(i);
                    continue;
                }
                cur_len = i - open_indx.top();
                max_len = max(max_len, cur_len);
            }
        }
        return max(max_len, cur_len);
    }
};

int main() {
    vector<pair<string, int>> tests = {
        make_pair("(()))())(", 4),
        make_pair(")()())()()(", 4),
        make_pair("(((()((((((())", 4),
        make_pair("(((()((((((()", 2),
        make_pair("(()))((((((())", 4),
        make_pair("((()))((((((())", 6),
    };
    Solution sol;
    for(auto test: tests) {
        auto ret = sol.longestValidParentheses(test.first);
        if (ret == test.second) {
            cout << "Test Passed! expected = " << test.second << " and received = " << ret << endl;
        } else {
            cout << "Test Failed! expected = " << test.second << " and received = " << ret << endl;
        }
    }
}