/**
 * See LC 486 for PS
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int max_score(vector<int> &nums, int i, int j, int total) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] == -1) {
            dp[i][j] = total - min(max_score(nums, i + 1, j, total - nums[i]), max_score(nums, i, j-1, total - nums[j]));
        }
        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int to_win = total / 2 + (total%2);
        int nums_size = nums.size();
        dp.resize(nums_size,vector<int>(nums_size,-1));
        return to_win <= max_score(nums, 0, nums_size-1, total);
    }
};

int main () {
    vector<pair<vector<int>,bool>> tests = {
        make_pair(vector<int>{1,5,2},false),
        make_pair(vector<int>{1,5,233,7}, true),
        make_pair(vector<int>{1000,1000,1000,0,0,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000},true),
        make_pair(vector<int>{3606449,6,5,9,452429,7,9580316,9857582,8514433,9,6,6614512,753594,5474165,4,2697293,8,7,1}, false)
    };
    for (auto test: tests) {
        Solution sol;
        assert(sol.predictTheWinner(test.first) == test.second);
    }
    cout << "All Tests Passed!!\n\n";
}