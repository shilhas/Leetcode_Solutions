/**
 * See LC 152 for PS
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int curr_max = 1;
        int curr_min = 1;
        for (int val: nums){
            int tmp = curr_max*val;
            curr_max = max(tmp, max(curr_min*val, val));
            curr_min = min(tmp, min(curr_min*val, val));
            ans = max(curr_max, ans);
        }
        return ans;
    }
};

template<typename T>
void print_vec(vector<T>vals) {
    for (T val: vals) {
        cout << val << "\t";
    }
    cout << ":";
}

int main(){
    vector<vector<int>> tests {
        {-2},
        {-3, -1, -1},
        {-2,3,-4},
        {-2,0,-4},
        {2, 3, 7, 0, -1, 9, -12},
        {2, 3, 7, 0, 1, 9, -12},
        {2, 3, 0, 7, -1, 9, -12}
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.maxProduct(test);
        cout << "Max Product for\t";
        print_vec(test);
        cout << ret << endl;
    }
}