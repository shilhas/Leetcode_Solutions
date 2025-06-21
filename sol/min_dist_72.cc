/**
 * See LC 72 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < 1 or word2.size() < 1) {
            return max(word2.size(), word1.size());
        }
        int lw1 = word1.size();
        int lw2 = word2.size();

        vector<vector<int>> dp(lw1+1, vector<int>(lw2+1));
        dp[0][0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 1; i < dp[0].size(); i++) {
            dp[0][i] = i;
        }

        for (int row = 1; row < dp.size(); row++) {
            for (int col = 1; col < dp[0].size(); col++) {
                if (word1[row-1] == word2[col-1]) {
                    dp[row][col] = dp[row-1][col-1];
                    continue;
                }
                dp[row][col] = 1 + min({dp[row-1][col-1], dp[row-1][col], dp[row][col-1]});
            }
        }
        return dp[lw1][lw2];
    }
};

int main () {
    vector<pair<string, string>> tests = {
        make_pair("horse", "ros"),
        make_pair("intention", "execution"),
        make_pair("a", "a"),
    };

    Solution sol;
    for (auto test : tests) {
        cout << "Result for input " << test.first << ", " << test.second << " is: " << sol.minDistance(test.first, test.second) << endl;
    }
}