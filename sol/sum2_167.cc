/**
 * See description of Leetcode problem no. 167
 */
#include <iostream>
#include <vector>

using namespace std;

    vector<int> twoSum(vector<int>& numbers, int target) {
        const int last_idx = numbers.size() - 1;
        int il = 0, ir = last_idx;
        while (il <= (last_idx - 1)) {
            while ((numbers[il] + numbers[ir]) > target){
                if (ir > il){
                    ir--;
                } else {                    
                    break;
                }
            }
            if ((numbers[il] + numbers[ir]) == target) break;
            il++;
        }
        return vector<int>{il+1,ir+1};
    }

typedef struct{
    /* data */
    vector<int> nums;
    int target;
    pair<int, int>result;
}TestVal_typ;


TestVal_typ tests[] = {
    {
        .nums = {2,7,11,15},
        .target = 9,
        .result = make_pair<int, int>(1,2)
    },
    {
        .nums = {2, 3, 4},
        .target = 6,
        .result = make_pair<int, int>(1,3)
    },
    {
        .nums = {-1, 0},
        .target = -1,
        .result = make_pair<int, int>(1,2)
    },
    {
        .nums = {11, 23, 45, 69, 71, 84, 90, 98, 99},
        .target = 183,
        .result = make_pair<int, int>(6,9)
    }
};

int main (void) {
    for(auto test: tests) {
        vector<int> ret = twoSum(test.nums, test.target);
        if((test.result.first == ret[0]) && (test.result.second == ret[1])) {
            cout << "Test Passed" << endl;
        } else {
            cout << "Test Failed, expected :" << test.result.first << " " << test.result.second << 
            " got :" << ret[0] << " " << ret[1] << endl;
        }
    }
}