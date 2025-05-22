/**
 * Write code to find a peak element. A peak element is defined as element that is greater than it's neighbours. 
 * Set can have more then 1 peak element so return index of any one
 */
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
        auto nsize = nums.size();
        if(nsize < 2) {
            return 0;
        } else if (nsize == 2) {
            return (nums[0] > nums[1]) ? 0:1;
        } else {
            for(auto i = 0; i < nsize - 1; i++) {
                auto left = -2^32;
                if (i > 0) {
                    left = nums[i - 1];
                } 
                auto right = nums[i+1];
                
                if ((nums[i] > left) & (nums[i] > right)) {
                    return i;
                }
            }
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return nsize - 1;
            }
        }
}

vector<pair<vector<int>, int>>test = {
    make_pair(vector<int>{1,2,3,1}, 2),
    make_pair(vector<int>{1,2,1,3,5,6,4}, 1),
    make_pair(vector<int>{1,2,3,4,5}, 4),
    make_pair(vector<int>{1,2}, 1)
};

int main(void) {
    for(auto t: test) {
        auto ret = findPeakElement(t.first);
        if (ret == t.second) {
            cout << "Test Passed" << endl;
        } else {
            cout << "Test failed, expected " << t.second << " got " << ret << endl;
        }
    }
    return 0;
}