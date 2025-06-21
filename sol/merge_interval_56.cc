/**
 * See LC 56 for PS
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
            return a[0] < b[0];
        });
        vector<vector<int>> ret;
        vector<int>prev = intervals[0];
        for (auto it = intervals.begin()+1; it != intervals.end(); it++) {
            if (prev[0] <= it[0][0] & prev[1] >= it[0][0]) {
                prev[1] = max(it[0][1], prev[1]);
            } else {
                ret.push_back(prev);
                prev = it[0];
            }
        }
        ret.push_back(prev);
        return ret;
    }
};

void print_result(vector<vector<int>>test, vector<vector<int>> res) {
    cout << "\nFor test interval: ";
    for (auto inter: test) {
        cout << "{ "<< inter[0] << " ," << inter[1] << " } ";
    }
    cout << "\nMerged intervals is:";
    for (auto inter: res) {
        cout << "{ "<< inter[0] << " ," << inter[1] << " } ";
    }
}

int main() {
    vector<vector<vector<int>>> tests = {
        {
            {1, 4}, {3, 8}, {7, 9}, {12, 15}
        },

        {
            {1, 4}, {5, 8}, {9, 11}, {12, 15}
        }
    };
    Solution sol;
    for (auto test: tests) {
        auto ret = sol.merge(test);

        print_result(test, ret);
    }
}