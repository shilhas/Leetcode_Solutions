/**
* See LC 87 for PS
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, set<string>>dp;
public:
    set<string> get_scrambled(string s1) {
        set<string> ret;
        if (dp.find(s1) != dp.end()) return dp[s1];
        if (s1.length() == 1) {
            ret.insert(s1);
            dp[s1] = ret;
            return ret;
        }
        
        for(int i = 1; i < s1.length(); i++) {
            // string tmp1 = s1.substr(0,i);
            // string tmp2 = s1.substr(i);
            auto sc1 = get_scrambled(s1.substr(0,i));
            auto sc2 = get_scrambled(s1.substr(i));
            for (auto p1: sc1) {
                for (auto p2: sc2) {
                    ret.insert(p1+p2);
                    ret.insert(p2+p1);
                }
            }
        }
        dp[s1] = std::move(ret);
        return dp[s1];
    }
    
    bool isScramble(string s1, string s2) {
        // divide string s1 from index 1 to n - 1
        // check create swapped and unswapped version
        // if len of any part > 1 repeat step
        if (s1 == s2) return true;
        
        set<string> scrambled = get_scrambled(s1);
        for (auto v: scrambled) {
            if (v == s2) return true;
        }
        
        return false;
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
        // auto measure_delta = [](auto start){
        //     auto end = chrono::steady_clock::now();
        //     cout << "\n\nTime needed for computation: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "\n\n";
        // };
        // auto start = chrono::steady_clock::now();
        if (sol.isScramble(test[0], test[1])) {
            cout << test[1] << " is scrambled version of " << test[0]<<endl;
        } else {
            cout << test[1] << " is not scrambled version of " << test[0]<<endl;
        }
        // measure_delta(start);
    }
}
