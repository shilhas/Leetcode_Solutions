/**
 * See LC 26 for PS
 */
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return 1;
        int entry_point = 1;
        int prev = 0;
        int next = 1;
        while (next < nums.size()) {
            if (nums[next] == nums[prev]) {
                next++;
                continue;
            }
            nums[entry_point] = nums[next];
            prev = next;
            entry_point++;
            next++;
        }
        return entry_point;
    }
};