/**
 * See LC 241 for PS
 */
#include <bits/stdc++.h>

using namespace std;

// create array of numbers and operation separate
// 

class Solution {
    unordered_map<string,vector<int>>memo;
public:    
    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) return memo[expression];
        vector<int> res;
        bool is_number = true;

        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                is_number = false;
                auto left_res = diffWaysToCompute(expression.substr(0,i));
                auto right_res = diffWaysToCompute(expression.substr(i+1));
                for (auto left_val:left_res) {
                    for (auto right_val: right_res) {
                        switch(c) {
                            case '*':
                                res.push_back(left_val * right_val);
                                break;
                            case '-':
                                res.push_back(left_val - right_val);
                                break;
                            default:
                                res.push_back(left_val + right_val);
                                break;
                        }
                    }
                }
            }
        }
        if (is_number) {
            res.push_back(stoi(expression));
        }
        memo[expression] = res;
        return res;
    }
};

int main() {
    vector<string>tests = {
        "2-1-1",
        "2*3-4*5",
        "7-8*2+9*1"
    };

    for (auto test:tests) {
        Solution sol;
        auto res = sol.diffWaysToCompute(test);
        cout << "For expression " << test <<  " Result: { ";
        for (auto val: res) {
            cout << val << " ";
        }
        cout << "}\n";
    }
}