/**
* See LC 131 for PS
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<string>> res;
public:
    bool isPalindrome(string& s) {
        if (s.size() == 1) return true;
        int l = 0;
        int r = s.size() - 1;
        while(l <= r) {
          if (s[l] != s[r]) return false;
          l++; r--;
        }
        return true;
    }
    void dfs(int i, string& s, vector<string>& part) {
        if (i >= s.size()) {
            res.push_back(part);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            auto substr = s.substr(i, (j + 1 - i));
            if (isPalindrome(substr)) {
                part.push_back(substr);
                dfs(j+1, s, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size() < 2) return {{s}};
        vector<string> part;
        dfs(0, s, part);
        return this->res;
    }
};


int main () {
    vector<string> tests = {"cdd","titfortat", "aab", "malayalam"};
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