/**
 * See LC 128 for problem statement
 */

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int longest_streak = 0;
        // METHOS 1: Using set
        // set<int> n_set(nums.begin(), nums.end());

        // for (auto num: n_set) {
        //     int curr_streak = 1;
        //     if (n_set.find(num -1) == n_set.end()) {
        //         int curr = num;
        //         while (n_set.find(curr + 1) != n_set.end()) {
        //             curr++;
        //             curr_streak++;
        //         }
        //     }
        //     longest_streak = max(longest_streak, curr_streak);
        // }

        // Method 2: Using sorting
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int curr_streak = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (prev == nums[i]) {
                //skip
                continue;
            } else if (prev == nums[i] - 1) {
                curr_streak++;
            } else {
                longest_streak = max(curr_streak, longest_streak);
                curr_streak = 1;
            }
            prev = nums[i];
            
        }
        longest_streak = max(curr_streak, longest_streak);
        return longest_streak;
    }
};

int main() {
    vector<int> test = {9,1,4,7,3,-1,0,5,8,-1,6};
    Solution sol;
    cout  << "Longest streak:" << sol.longestConsecutive(test) << "\n\n";
}