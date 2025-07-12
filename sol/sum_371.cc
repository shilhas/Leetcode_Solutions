/**
 * See LC 371 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int n1 = (a >> i & 1);
            int n2 = (b >> i & 1);
            if (n1 == 0 and n2 == 0) {
                res |= carry << i;
                carry = 0;
            } else if (n1 == 1 and n2 == 1) {
                 res |= carry << i;
                 carry = 1;
            } else {
                res |= (carry ^ 1) << i;
            }
        }
        return res;
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