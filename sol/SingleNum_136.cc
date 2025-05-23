/**
 * See LC 136 for PS
 */

 #include <vector>
 #include <algorithm>
 #include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int num: nums) {
            ret ^= num;
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> tests = {
        {2, 2, 1},
        {4,1,2,1,2},
        {1}
    };
    Solution sol;
    for (auto test: tests) {
        cout << sol.singleNumber(test) << "\n";
    }
}