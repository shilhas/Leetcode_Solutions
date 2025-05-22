/**
 * See LC 238 for PS
 */

 #include <iostream>
 #include <vector>

 using namespace std;
 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total_prod = 1;
        pair<int, int> zeros= {0,0};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeros.first++;
                zeros.second = i;
                if (zeros.first > 1) {
                    return vector<int>(nums.size(), 0);
                }
            } else {
                total_prod *= nums[i];
            }
        }
        if (zeros.first) {
            vector<int> ret(nums.size(), 0);
            ret[zeros.second] = total_prod;
            return ret;
        }
        for (int i = 0; i < nums.size(); i++) {

            nums[i] = total_prod / nums[i];
        }
        return nums;
    }
};

int main () {
    vector<vector<int>> tests {
        {1,2,3,4},
        {-1,1,0,-3,3}
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.productExceptSelf(test);
        for (auto val: ret) {
            cout << val << "\t";
        }
        cout << "\n";
    }
}
 
 