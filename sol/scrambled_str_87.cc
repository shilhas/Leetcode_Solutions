/**
* See LC 87 for PS
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, bool>dp;
public:
    
    bool isScramble(string s1, string s2) {
        // divide string s1 from index 1 to n - 1
        // check create swapped and unswapped version
        // if len of any part > 1 repeat step
        int len = s1.length();
        if (s1 == s2) return true;
        if (len == 1) return false;

        if (dp.find(s1+s2) != dp.end()) return dp[s1+s2];
        
        auto split_str = [](string& str, int i) -> pair<string, string>{
            return make_pair(str.substr(0,i), str.substr(i));
        };
        auto key = s1 + s2;
        for (int i = 1; i < len; i++) {
            auto s1_split = split_str(s1, i);
            auto s2_split = split_str(s2, i);
            if (isScramble(s1_split.first, s2_split.first) && isScramble(s1_split.second, s2_split.second)){
                return dp[key] = true;
            }
            s2_split = split_str(s2, len-i);
            if (isScramble(s1_split.first, s2_split.second) && isScramble(s1_split.second, s2_split.first)){
                return dp[key] = true;
            }
        }
        
        return dp[s1+s2] = false;
    }
};

int main () {
    vector<vector<string>> tests = {
        {"great", "rgeat"},
        {"abcde", "caebd"},
        {"abb", "bab"},
        {"abcdbdacbdac", "bdacabcdbdac"}
    };
    for (auto test: tests) {
        Solution sol;
        auto measure_delta = [](auto start){
            auto end = chrono::steady_clock::now();
            cout << "\nTime needed for computation: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "\n\n";
        };
        auto start = chrono::steady_clock::now();
        if (sol.isScramble(test[0], test[1])) {
            cout << test[1] << " is scrambled version of " << test[0]<<endl;
        } else {
            cout << test[1] << " is not scrambled version of " << test[0]<<endl;
        }
        measure_delta(start);
    }
}
