/**
 * See LC 918 for PS
 */
#include <vector>
#include <climits>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        int currMax = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMin = nums[0];
        int totalSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currMax = max(currMax+nums[i],nums[i]);
            currMin = min(currMin+nums[i],nums[i]);
            totalSum += nums[i];
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        int diff = totalSum<0? (abs(minSum) - abs(totalSum)):totalSum - minSum;
        
        if (totalSum != minSum) maxSum = max(maxSum, diff);
        
        return maxSum;
    }
};

int main() {
    vector<pair<vector<int>,int>>tests = {
        make_pair(vector<int>({1,-2,3,-2}),3),
        make_pair(vector<int>({5,-3,5}),10),
        make_pair(vector<int>({-3,-2,-3}),-2),
        make_pair(vector<int>({11,-1, 2, 1, 5}),19),
    };

    Solution sol;
    for (auto test: tests) {
        int ret = sol.maxSubarraySumCircular(test.first);
        assert(ret == test.second);
    }
    cout << "All testcases passed!!\n";
}