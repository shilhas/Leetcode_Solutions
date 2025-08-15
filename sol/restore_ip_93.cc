/**
 * See LC 93 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
        void valid_ips(string& s, int indx, vector<string> num,vector<string>& res) {
            if (num.size() == 4 and indx == s.length()) {
                res.push_back(num[0] + '.' + num[1] + '.' + num[2] + '.' + num[3]);
            }
            if (indx >= s.length()) {
                return;
            }
            // get next num
            
            for (int i = 0; i < 3; i++) {
                auto curr = s.substr(indx, i+1);
                if (curr == "0") {
                    num.push_back(curr);
                    valid_ips(s, indx+1, num, res);
                    break;
                } else if (stoi(curr) < 256) {
                    num.push_back(curr);
                    valid_ips(s, indx+i+1, num, res);
                    num.pop_back();
                }
            }
        }

        vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            valid_ips(s, 0, {}, res);
            return res;
        }
};

#include "print_helper.h"

int main() {
    vector<string> tests = {
        "25525511135", "0000", "101023"
    };

    for (auto test: tests) {
        Solution sol;
        auto res = sol.restoreIpAddresses(test);
        cout << "Input: " << test << "\n";
        cout << "Output: ";
        print_vec(res);
        cout << "\n\n";
    }
}