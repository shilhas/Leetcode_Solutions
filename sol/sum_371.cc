/**
 * See LC 371 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        return getSum(a^b, (a&b)<<1);
    }
};

int main() {
    vector<vector<int>> tests = {
        {1,2,3},
        {4, -5, -1},
        {4, -4, 0},
        {4, -3, 1},
        {6, 9, 15},
        {-6, -6, -12}
    };

    for (auto test: tests) {
        Solution sol;
        int ret = sol.getSum(test[0], test[1]);
        assert(ret == test[2]);
    }
    cout << "All Test cases passed!!";
}