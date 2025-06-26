/**
* See LC 131 for PS
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<vector<int>> dp;
public:
    void dfs(int i, string& s, vector<string>& part) {
        if (i >= s.size()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            auto substr = s.substr(i, (j+1 - i));
            if (dp[i][j] == 1) {
                part.push_back(substr);
                dfs(j+1, s, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size() < 2) return {{s}};
        vector<string> part;
        int slen = s.size();
        dp.resize(slen, vector<int>(slen, -1));
        for (int i = 0; i < slen; i++) {
            dp[i][i] = 1;
        }
        auto check_dp = [](int dp_val) {return dp_val == -1 or dp_val == 1;};
        for (int i = slen - 2; i > -1; i--) {
            for (int j = i+1; j < slen; j++) {
                if (s[i] == s[j] and check_dp(dp[i+1][j-1])) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        dfs(0, s, part);
        return this->res;
    }
};


int main () {
    vector<string> tests = {"coop", "canon", "aab", "malayalam"};
    for (auto test: tests) {
        Solution sol;
        cout << "Input: " << test << "\t";
        for (auto res: sol.partition(test)) {
            for (auto s: res) {
                cout << s << "  ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
}
