/**
 * See LC 221 for PS
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool next_cell(vector<vector<char>>& matrix, int& cur_row, int& cur_col, int sq_size) {
        if (cur_col + sq_size > matrix[0].size() and cur_row + sq_size > matrix.size()) return false;
        if (cur_col + sq_size < matrix[0].size()) {
            cur_col++;
        } else {
            cur_row++;
            cur_col = 0;
        }
        return true;
    }

    bool is_square(vector<vector<char>>& matrix, int s_row, int s_col, int sq_size){
        // check if the square is 
        if (sq_size == 1 and matrix[s_row][s_col] == '1') return true;

        for (int i = s_row; i < s_row + sq_size; i++) {
            for (int j = s_col; j < s_col + sq_size; j++) {
                if (matrix[i][j] == '0') return false;
            }
        }
        return true;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int sq_size = 1;
        int row_end = matrix.size();
        int col_end = matrix[0].size();
        int row = 0;
        int col = 0;
        while (row < row_end) {
            if (matrix[row][col] == '1') {
                if (is_square(matrix, row, col, sq_size)) {
                    sq_size++;
                    continue;
                }
            }
            if (!next_cell(matrix, row, col, sq_size)) break;
        }
        return (sq_size - 1)*(sq_size - 1);
    }
};

int main() {
    vector<vector<char>> test = {
        // {'0','0','0', '0','0','0'},
        // {'0','1','1', '1','0','0'},
        // {'0','1','1', '1','0','0'},
        // {'0','1','1', '1','0','0'},
        {'0', '1'},
        {'1', '0'}
        // {'1','0','1','0','0'},
        // {'1','0','1','1','1'},
        // {'1','1','1','1','1'},
        // {'1','0','0','1','0'}
    };
    Solution sol;
    int ret = sol.maximalSquare(test);
    cout << "Max square size = " << ret << endl;
}