/**
 * See LC 300 for PS (LIS -> longest increasing subsequence)
 */

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return 1;
        vector<int> LIS(nums.size(), 1);
        int curr_max = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
                curr_max = max(LIS[i], curr_max);
            }
        }
        return curr_max;
    }
};

int main() {
    vector<pair<vector<int>, int>>tests = {
        make_pair(vector<int>{10,9,2,5,3,7,101,18},4),
        make_pair(vector<int>{0,1,0,3,2,3},4),
        make_pair(vector<int>{7,7,7,7,7},1),
        make_pair(vector<int>{0,1,0,3,3,3},3),
    };
    Solution sol;
    for (auto test: tests) {
        assert(test.second == sol.lengthOfLIS(test.first));
    }
    cout << "All tests passed !!\n";
}