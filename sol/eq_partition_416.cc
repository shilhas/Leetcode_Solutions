/**
 * See LC 416 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int target = std::reduce(nums.begin(), nums.end());
        if (target % 2) {
            return false;
        }
        target /= 2;
        unordered_set<int> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); i++) {
            auto copy_sums = sums;
            for (int val: copy_sums) {
                if (val + nums[i] == target) return true;
                sums.insert(val + nums[i]);
            }
        }
        return false;
    }
};

int main() {
    vector<pair<vector<int>,bool>> tests = {
        make_pair(vector<int>{1,5,11,5},true),
        make_pair(vector<int>{1,2,3,5},false),
        make_pair(vector<int>{1,5,12,5},false),
        make_pair(vector<int>{8},false),
        make_pair(vector<int>{8,1,7,9,13,78,45,30,11,3,4,5,16,22,24},true)
    };

    Solution sol;
    for (auto test: tests) {
        assert(sol.canPartition(test.first)==test.second);
    }
    cout << "All tests passed!\n\n";
}