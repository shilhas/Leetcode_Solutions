/**
 * See LC 215 for PS
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    pair<int, int> get_max_min(vector<int>& nums){
        int max_v = INT_MIN;
        int min_v = INT_MAX;
        for (auto num: nums) {
            max_v = max(num, max_v);
            min_v = min(num, min_v);
        }
        return make_pair(max_v, min_v);
    }

    int findKthLargest(vector<int>& nums, int k) {
        auto max_min = get_max_min(nums);
        int max_val = max_min.first;
        int min_val = max_min.second;

        vector<int>freq((max_val - min_val) + 1, 0);
        for (int num: nums) {
            freq[num - min_val] ++;
        }
        int i = freq.size() - 1;
        while(i){
            k -= freq[i];
            if (k <= 0){
                return i + min_val;
            }
            i--;
        }
        return min_val;
    }
};

template<typename T>
void print_vector(vector<T> vec){
    for (T val: vec) {
        cout << val <<" ";
    }
}

int main() {
    vector<vector<int>>tests = {
        {50, 12, 33, 50, 33, 22, 15, 16, 5, 9, 17, 17, 33, 7},
        {50, 12, 33, 50, 33, 22, 15, 16, 5, 9, 17, 17, 33, 5}
    };
    Solution sol;
    cout << "\n";
    for (auto test: tests) {
        int k = test.back();
        vector<int> test_data = {test.begin(), test.end() - 1};
        int ret = sol.findKthLargest(test_data, k);

        cout << "kth largest val in ";
        print_vector(test_data);
        cout << "is :" << ret << "\n";
    }
}