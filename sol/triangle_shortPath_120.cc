/**
 * See LC 120 for PS
 */
#include <bits/stdc++.h>
 
using namespace std;

// 1. can move row+1 or (row+1, col+1)
// only integer values?
// constraint on dimension of the triangle?

// Aproach:
// 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];
        int curr_min = INT_MAX;
        int row_count = triangle.size();
        for (int row = 1; row < row_count; row++) {
            for (int col = 0; col < row+1; col++) {
                if (col > 0) {
                    triangle[row][col] += col==row? triangle[row-1][col-1]:min(triangle[row-1][col], triangle[row-1][col-1]);
                } else {
                    triangle[row][col] += triangle[row-1][col];
                }
                if (row == row_count - 1){
                    curr_min =  min(curr_min, triangle[row][col]);
                }
            }
        }
        return curr_min;
    }
};


int main() {
    vector<vector<vector<int>>> tests = {
        {{2},{3,4},{6,5,7},{4,1,8,3}},
        {{-10}}
    };
    for (auto test: tests) {
        Solution sol;
        auto ret = sol.minimumTotal(test);
        cout << "Result: " << ret << endl;
    }
}