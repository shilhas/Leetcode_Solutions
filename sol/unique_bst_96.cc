/**
* See LC 96 for PS
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int>dp;
public:
    int get_numTrees(int n) {
        if (n < 0) return 0;
        if (dp[n] == -1){
            int res = 0;
            for (int i = 0, j = n-1; i < n; i++, j--){
                res += get_numTrees(i) * get_numTrees(j);
            }
            dp[n] = res;
        }
        return dp[n];
    }

    int numTrees(int n) {
        if (n == 1) return 1;
        dp.resize(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        return get_numTrees(n);
    }
};

int main() {
    vector<int>tests = {
        1, 3, 2, 4, 5
    };
    for (auto test: tests) {
        Solution sol;
        cout << "Unique BST for graphs with node/s " << test << " is " << sol.numTrees(test) << endl;
    }
}
