/**
 * See LC 3 for PS
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 1;
        int right = 1;
        string curr_ss = s.substr(0,1);
        while (right < s.length()) {
            auto cp = curr_ss.find(s[right]);
            if (cp != std::string::npos) {
                longest = max(longest, static_cast<int> (curr_ss.length()));
                curr_ss = curr_ss.substr(cp+1,curr_ss.length() - cp);   
            }
            curr_ss += s[right];
            right++;
        }
        longest = max(longest, static_cast<int>(curr_ss.length()));
        return longest;
    }
};

int  main() {
    vector<string> tests = {
        "something", "leetcode", "Apple", "abcdefghijklmnopqrstuvwxyzg", "aa"
    };
    Solution sol;
    for (auto test: tests) {
        int ret = sol.lengthOfLongestSubstring(test);
        cout << "Longest non-repeating substring in " << test << " is " << ret << endl;
    }
}