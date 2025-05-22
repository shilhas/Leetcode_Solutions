/**
 * Find majority element in the array, majority element is one that appears atleast n / 2 
 * times where n is the total number or elements
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    // Approach 1: sorting
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() / 2];

    // Approach 2: Frequency count
    int count = 1;
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == ans) {
            count++;
        } else {
            count--;
        }
        if (count < 0) {
            ans = nums[i];
            count = 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> tests = {
        {2, 2, 1},
        {3, 2, 4, 3, -1, 3, 3},
        {2,2,1,1,1,2,2}
    };
    for (auto test: tests) {
        int ret = majorityElement(test);

        cout << ret << "\n";
    }
}