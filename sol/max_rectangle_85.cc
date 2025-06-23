/**
 * See LC 85 for PS
 */
#include <bits/stdc++.h>

 using namespace std;

class Solution {
public:
    int curr_row_max_area(vector<int>& heights) {
        int max_area = 0;
        deque<int> dq;
        int curr_row_size = heights.size();
        for (int i = 0; i <= curr_row_size; i++) {
            int curr_height = i == curr_row_size? 0:heights[i];
            while(!dq.empty() and curr_height < heights[dq.back()]) {
                int indx = dq.back();
                dq.pop_back();
                int width = dq.empty()? i: i - dq.back() - 1;
                max_area = max(max_area, heights[indx]*width);
            }
            dq.push_back(i);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() < 2 and matrix[0].size() < 2) {
            return matrix[0][0] == '1' ? 1:0;
        }
        vector<vector<int>> col_heights(matrix.size(), vector<int>(matrix[0].size(),0));
        for (int c = 0; c < matrix[0].size(); c++) {
            col_heights[0][c] = matrix[0][c] - '0';
        }
        for (int row = 1; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[0].size(); col++) {
                col_heights[row][col] = matrix[row][col] == '0'? 0:col_heights[row-1][col]+1;
            }
        }
        int max_area = 0;
        for (auto c_row: col_heights) {
            max_area = max(max_area, curr_row_max_area(c_row));
        }
        return max_area;
    }

};

int main() {
    vector<pair<vector<vector<char>>,int>> tests = {
        // test 1: expect 6
        make_pair(vector<vector<char>>{
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        },6),
        // test 2: expect 1
        make_pair(vector<vector<char>>{
            {'1'}
        },1),
        // test 3 expect 12
        make_pair(vector<vector<char>>{
            {'0','0','0','0','0','0','0','0','0','0','0','0'},
            {'0','1','0','0','1','0','0','1','1','0','0','0'},
            {'0','1','1','0','1','0','0','1','1','0','0','0'},
            {'0','1','1','1','1','0','0','1','0','0','0','0'},
            {'0','1','1','1','1','0','0','0','0','0','0','0'},
            {'0','1','1','1','1','0','0','0','0','0','0','0'},
            {'0','0','1','0','0','0','0','0','0','0','0','0'}
        },12)
    };
    Solution sol;

    for (auto test: tests) {
        int res = sol.maximalRectangle(test.first);
        assert(res == test.second);
    }
    cout << "\nAll testcases passed!!\n";
}