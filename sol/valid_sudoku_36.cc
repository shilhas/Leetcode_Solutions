/**
 * See LC 36 for PS
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>rows(9, vector<bool>(9, false));
        vector<vector<bool>>cols(9, vector<bool>(9, false));
        vector<vector<bool>>boxes(9, vector<bool>(9, false));
        
        auto get_box = [](int r, int c) ->int {
            return (r/3)*3 + c/3;
        };
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                
                if (board[row][col] == '.') continue;

                int cur = board[row][col] - '0' - 1;
                if (rows[row][cur]) return false;
                rows[row][cur] = true;
                if (cols[col][cur]) return false;
                cols[col][cur] = true;
                int curr_box = get_box(row, col);
                if (boxes[curr_box][cur]) return false;
                boxes[curr_box][cur] = true;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> tests = {
        {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','7','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    bool ret = sol.isValidSudoku(tests);
    if (ret) {
        cout << "It is valid Sudoku\n";
    } else {
        cout << "It is NOT a valid Sudoku\n";
    }
}