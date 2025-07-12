/**
 * See LC 90 for PS
 */
#include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>>res;
public:
    void get_subset(vector<int>& nums, int next, vector<int>& ss) {
        if (next >= nums.size()) {
            res.push_back(ss);
            return;
        }
        int ns = nums.size();
        ss.push_back(nums[next]);
        get_subset(nums, next+1, ss);
        ss.pop_back();
        while(next < ns - 1 and nums[next] == nums[next+1]) {
            next++;
        }
        get_subset(nums, next+1, ss);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ss = {};
        sort(nums.begin(), nums.end());
        get_subset(nums, 0, ss);
        return res; 
    }
};

template<typename T>
void print_vec(vector<T>vals) {
    for (T val: vals) {
        cout << val << "\t";
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> tests = {
        {1,2,2},
        {1,2,3,4}
    };

    for (auto test: tests) {
        Solution sol;
        auto ret = sol.subsetsWithDup(test);
        cout << "Input: ";
        print_vec(test);
        cout << "Output: ";
        for (auto r: ret) {
            print_vec(r);
        }
    }
}