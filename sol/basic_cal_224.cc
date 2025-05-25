/**
 * See LC 224 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<pair<int, char>> num_satck;
        int lhs = 0;
        string next_num = "";
        char op = '+';
        auto compute = [](int l_val, string r, char op) -> int{
            int r_val = stoi(r);
            return op == '+'? l_val + r_val: l_val - r_val;
        };

        for(int i = 0; i < s.length(); ) {
            while (s[i] >= '0' and s[i] <= '9') {
                next_num += (s[i]);
                i++;
            }
            if (next_num.length() > 0){
                lhs = compute(lhs, next_num, op);
                next_num = "";
            }
            switch(s[i]) {
                case '+':
                case '-':
                    op = s[i];
                    break;
                case '(':
                    //push to stack
                    num_satck.push(make_pair(lhs,op));
                    lhs = 0;
                    op = '+';
                    break;
                case ')':
                    // pop from stack
                    if (!num_satck.empty()) {
                        auto last_v = num_satck.top();
                        num_satck.pop();
                        if (last_v.second == '+') {
                            lhs += last_v.first;
                        } else {
                            lhs = last_v.first - lhs;
                        }
                    }
                    break;
                default:
                    break;
            }
            i++;
        }
        return lhs;    
    }
};

int main() {
    vector<pair<string,int>> tests = {
        make_pair("1 + (5 - 3)",3),
        make_pair("1 + (5 - (3 + 2))",1),
        make_pair("(1 - 5) + (5 - (3 + 2))",-4),
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.calculate(test.first);
        assert(ret == test.second);
    }
    cout << "\nAll tests passed!!\n";
}