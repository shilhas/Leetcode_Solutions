/**
 * See LC 375 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>>dp;
public:
    int recurse(int start, int end) {
        if (start >= end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(recurse(i+1,end), recurse(start, i-1)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        if (n < 4) {
            return n - 1;
        }
        dp.resize(n+1, vector<int>(n + 1, -1));
        return recurse(1, n);
    }
};

int main() {
    vector<int> tests = {1, 2, 3, 10, 99};
    for (auto test: tests) {
        Solution sol;
        cout << "\nInput: " << test << " Output: " << sol.getMoneyAmount(test);
    }
    cout << "\n\n";
}