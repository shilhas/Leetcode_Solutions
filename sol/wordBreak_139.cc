/**
 * See LC 139 for PS
 */
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size = s.size();
        vector<bool> dp(s_size+1, false);
        dp[s_size] = true;
        for(int i = s_size - 1; i >= 0; i--) {
            for (string word: wordDict){
                if (s.substr(i, word.size()) == word) {
                    dp[i] = dp[i + word.size()];
                }
                // valid word
                if (dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main() {
    vector<pair<vector<string>, string>> tests = {
        make_pair(vector<string>{"cats","dog","sand","and","cat"},"catsandog"),
        make_pair(vector<string>{"dev", "stack", "developer", "tools"},"devstack"),
        make_pair(vector<string>{"dev", "stack", "developer", "tools"},"developertools"),
        make_pair(vector<string>{"dev", "stack", "developer", "tools"},"devtools"),
        make_pair(vector<string>{"dev", "stack", "developer", "tools"},"devtool"),
        make_pair(vector<string>{"leet","code"},"leetcode"),
        make_pair(vector<string>{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"}, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"),
    };
    Solution sol;
    for (auto test: tests) {
        if (sol.wordBreak(test.second, test.first)) {
            cout << "String " << test.second << " can be divided\n";
        } else {
            cout << "String " << test.second << " cannot be divided\n";
        }
    }
}